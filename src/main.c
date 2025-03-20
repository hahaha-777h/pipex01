/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:36:34 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/20 15:31:48 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	handle_here_doc(int ac, char *av[], t_pipex *pipex)
{
	static char	*filename = "/tmp/temp_file_for_heredoc";
	char		*line;

	pipex->in_fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (pipex->in_fd == -1)
		return ;
	line = get_next_line(STDIN_FILENO);
	while (ft_strcmp(line, ft_strjoin(av[2], "\n")))
	{
		if (write(pipex->in_fd, line, ft_strlen(line)) == -1)
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

// これ以外のときはopen, close, writeなどbashと違うところが失敗。
// static int	return_value(void)
// {
// 	if (!ft_strcmp(strerror(errno), "No such file or directory"))
// 		return (2);
// 	else if (!ft_strcmp(strerror(errno), "Permission denied"))
// 		return (126);
// 	else if (!ft_strcmp(strerror(errno), "command not found"))
// 		return (127);
// 	else
// 		return (0);
// }

/* mallocした変数はすべて構造体に入れて、cleanup()しやすくする　*/

int	main(int ac, char *av[], char *envp[])
{
	t_pipex	pipex;

	init_pipex(ac, &pipex);
	validate_args_and_open_file(ac, av, &pipex);
	if (errno != 0)
		perror(NULL);
	if (pipex.out_fd == -1)
		return (1);
	if (pipex.here_doc && pipex.in_fd == -1)
		return (2);
	if (envp == NULL)
		pipex.is_envp = false;
	pipex.cmd_paths = get_path(envp);
	if (pipex.cmd_paths == NULL && pipex.is_envp == true)
		return (3);
	pipex.cmd_args = get_cmds(ac, av, &pipex);
	if (pipex.cmd_args == NULL)
		return (4);
	execute_cmds(&pipex); // TODO
	// cleanup();   // TODO
	return (0);
}
