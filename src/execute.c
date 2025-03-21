/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:57:40 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/20 16:52:13 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	**allocate_pipes(t_pipex *pipex)
{
	int	**pipefd;
	int	pipe_count;

	pipefd = (int **)malloc((pipex->cmd_count - 1) * sizeof(int *));
	if (pipefd == NULL)
	{
		printf("malloc1 failed at allocate_pipes\n");
		return (NULL);
	}
	pipe_count = 0;
	while (pipe_count < pipex->cmd_count - 1)
	{
		pipefd[pipe_count] = (int *)malloc(2 * sizeof(int));
		if (pipefd[pipe_count] == NULL)
		{
			printf("malloc2 failed at allocate_pipes\n");
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

	if (pipex->cmd_args[cmds_i][0][0] == '/')
	{
		return (execve(pipex->cmd_args[cmds_i][0], pipex->cmd_args[cmds_i],
				NULL));
	}
	path_i = 0;
	while (pipex->cmd_paths[path_i])
	{
		pathname = ft_strjoin(pipex->cmd_paths[path_i],
				pipex->cmd_args[cmds_i][0]);
		execve(pathname, pipex->cmd_args[cmds_i], NULL);
		free(pathname);
		path_i++;
	}
	printf("exec failed at find_and_exec\n");
	return (127);
}

static int	close_dup_exec(t_pipex *pipex, int **pipefd, int cmds_i)
{
	if (cmds_i == 0)
		close_and_dup_first(pipex, pipefd);
	else if (cmds_i == pipex->cmd_count - 1)
		close_and_dup_last(pipex, pipefd, cmds_i);
	else
		close_and_dup_middle(pipex, pipefd, cmds_i);
	find_and_exec(pipex, cmds_i);
	return (127);
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
