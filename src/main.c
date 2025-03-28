/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:36:34 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/28 14:18:48 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*			*** What I would have done if I had more time ***

	1, Align error return values with Bash
	2, Include the name of the command in "Command not found" error messages

*/

static bool	validate_args_and_open_file(int ac, char *av[], t_pipex *pipex)
{
	if (ac < 5)
	{
		putstr_fd("Invalid args\n", 2);
		return (false);
	}
	if (!ft_strcmp(av[1], "here_doc"))
	{
		if (ac < 6)
			return (false);
		handle_here_doc(ac, av, pipex);
		return (true);
	}
	pipex->in_fd = open(av[1], O_RDONLY);
	pipex->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->out_fd == -1)
		putstr_fd("Permission denied\n", STDERR_FILENO);
	if (pipex->in_fd == -1 && errno == EACCES)
		putstr_fd("Permission denied\n", STDERR_FILENO);
	else if (pipex->in_fd == -1)
		putstr_fd("No such file or directory\n", STDERR_FILENO);
	return (true);
}

static bool	is_path(char **envp)
{
	size_t	row_i;

	row_i = 0;
	while (envp[row_i])
	{
		if (!ft_strncmp(envp[row_i], "PATH=", 5))
			return (true);
		row_i++;
	}
	return (false);
}

static bool	validate_cmds(int ac, char **av, t_pipex *pipex)
{
	int	char_pos;
	int	cmd_pos;

	if (pipex->here_doc == true)
		cmd_pos = 3;
	else
		cmd_pos = 2;
	while (av[cmd_pos] && cmd_pos < ac - 1)
	{
		char_pos = 0;
		while (av[cmd_pos][char_pos] == ' ')
			char_pos++;
		if (av[cmd_pos][char_pos] == '\0')
		{
			close(pipex->in_fd);
			close(pipex->out_fd);
			putstr_fd("Command not found\n", STDERR_FILENO);
			return (false);
		}
		cmd_pos++;
	}
	return (true);
}

static bool	validate_input(int ac, char *av[], t_pipex *pipex)
{
	if (!validate_args_and_open_file(ac, av, pipex))
		return (false);
	if (pipex->here_doc == true && pipex->in_fd == -1)
		return (false);
	if (validate_cmds(ac, av, pipex) == false)
		return (false);
	if (pipex->out_fd == -1)
	{
		cleanup(pipex);
		return (false);
	}
	return (true);
}

int	main(int ac, char *av[], char *envp[])
{
	t_pipex	pipex;

	init_pipex(ac, &pipex);
	if (validate_input(ac, av, &pipex) == false)
		return (1);
	if (is_path(envp))
	{
		pipex.cmd_paths = get_path(envp);
		if (pipex.cmd_paths == NULL)
			return (4);
	}
	pipex.cmd_args = get_cmds(ac, av, &pipex);
	if (execute_cmds(&pipex) != 0)
	{
		cleanup(&pipex);
		return (2);
	}
	cleanup(&pipex);
	return (0);
}
