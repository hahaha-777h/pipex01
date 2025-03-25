/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:36:34 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/25 15:12:39 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*			*** What I would have done if I had more time ***

	1, Align error return values with Bash
	2, Include the name of the command in "Command not found" error messages
	3,

*/

static void	handle_here_doc(int ac, char *av[], t_pipex *pipex)
{
	static char	*filename = "/tmp/temp_file_for_heredoc";
	char		*line;

	char *cmd_with_line_break ;
	pipex->in_fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (pipex->in_fd == -1)
		return ;
	line = get_next_line(STDIN_FILENO);
	cmd_with_line_break = ft_strjoin(av[2], "\n");
	if (cmd_with_line_break == NULL)
		return ;
	while (ft_strcmp(line, cmd_with_line_break))
	{
		if (putstr_fd(line, pipex->in_fd) == -1)
			return ;
		line = get_next_line(STDIN_FILENO);
	}
	pipex->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
}

static void	validate_args_and_open_file(int ac, char *av[], t_pipex *pipex)
{
	if (ac < 5)
	{
		pipex->is_valid_arg = false;
		putstr_fd("Invalid args\n", 2);
		return ;
	}
	if (!ft_strcmp(av[1], "here_doc"))
	{
		if (ac < 6)
		{
			pipex->is_valid_arg = false;
			return ;
		}
		pipex->here_doc = true;
		handle_here_doc(ac, av, pipex);
		return ;
	}
	pipex->in_fd = open(av[1], O_RDONLY);
	pipex->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
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

int	main(int ac, char *av[], char *envp[])
{
	t_pipex	pipex;
	int		execute_retval;

	init_pipex(ac, &pipex);
	validate_args_and_open_file(ac, av, &pipex);
	if (pipex.out_fd == -1 || (pipex.here_doc && pipex.in_fd == -1))
		return (1);
	if (is_path(envp))
	{
		pipex.cmd_paths = get_path(envp);
		if (pipex.cmd_paths == NULL)
			return (4);
	}
	pipex.cmd_args = get_cmds(ac, av, &pipex);
	if (pipex.cmd_args == NULL)
		return (5);
	execute_retval = execute_cmds(&pipex);
	if (execute_retval != 0)
	{
		write(STDERR_FILENO, "Command not found\n", 18);
		return (execute_retval);
	}
	cleanup(&pipex);
	return (0);
}
