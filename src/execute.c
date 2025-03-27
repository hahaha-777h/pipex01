/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:57:40 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/27 15:46:11 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	**allocate_pipes(t_pipex *pipex)
{
	int	**pipefd;
	int	pipe_count;

	pipefd = (int **)malloc((pipex->cmd_count - 1) * sizeof(int *));
	if (pipefd == NULL)
		return (NULL);
	pipe_count = 0;
	while (pipe_count < pipex->cmd_count - 1)
	{
		pipefd[pipe_count] = (int *)malloc(2 * sizeof(int));
		if (pipefd[pipe_count] == NULL)
		{
			while (pipe_count > 0)
				free(pipefd[--pipe_count]);
			free(pipefd);
			return (NULL);
		}
		pipe_count++;
	}
	return (pipefd);
}

static int	find_and_exec(t_pipex *pipex, int cmds_i)
{
	int		path_i;
	char	*pathname;
	char	***cmds;

	cmds = pipex->cmd_args;
	if (cmds[cmds_i][0][0] == '/')
		return (execve(cmds[cmds_i][0], cmds[cmds_i], NULL));
	path_i = 0;
	if (pipex->cmd_paths == NULL)
		return (127);
	if (cmds_i == 0 && pipex->in_fd == -1)
		return (0);
	while (pipex->cmd_paths[path_i])
	{
		pathname = ft_strjoin(pipex->cmd_paths[path_i], cmds[cmds_i][0]);
		if (pathname == NULL)
			return (0);
		execve(pathname, cmds[cmds_i], NULL);
		free(pathname);
		path_i++;
	}
	return (127);
}

static int	close_dup_exec(t_pipex *pipex, int **pipefd, int cmds_i)
{
	int	exec_retval;

	if (cmds_i == 0)
		close_and_dup_first(pipex, pipefd);
	else if (cmds_i == pipex->cmd_count - 1)
		close_and_dup_last(pipex, pipefd, cmds_i);
	else
		close_and_dup_middle(pipex, pipefd, cmds_i);
	if (!(cmds_i == 0 && pipex->in_fd == -1))
	{
		exec_retval = find_and_exec(pipex, cmds_i);
		if (exec_retval != 0)
			putstr_fd("Command not found or Permission denied\n", 2);
		return (exec_retval);
	}
	return (0);
}

static void	close_at_parent(int **pipefd, int cmds_i)
{
	if (cmds_i != 0)
	{
		close(pipefd[cmds_i - 1][0]);
		close(pipefd[cmds_i - 1][1]);
	}
}

int	execute_cmds(t_pipex *pipex)
{
	int	pid;
	int	**pipefd;
	int	cmds_i;

	pipefd = allocate_pipes(pipex);
	if (pipefd == NULL)
		return (5);
	cmds_i = 0;
	while (pipex->cmd_args[cmds_i] != NULL)
	{
		if (pipex->cmd_args[cmds_i + 1] != NULL)
			pipe(pipefd[cmds_i]);
		pid = fork();
		if (pid < 0)
			return (11);
		if (pid == 0)
			return (close_dup_exec(pipex, pipefd, cmds_i));
		close_at_parent(pipefd, cmds_i);
		cmds_i++;
	}
	free_pipes(pipex, pipefd);
	while (wait(NULL) > 0)
		;
	return (0);
}
