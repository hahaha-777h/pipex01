/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:57:40 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/19 18:59:04 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	**allocate_pipes(int ac, char *av[])
{
	int	**pipefd;
	int	pipe_count;

	(void)ac;
	(void)av;
	pipefd = (int **)malloc(2 * sizeof(int *));
	if (pipefd == NULL)
	{
		printf("malloc1 failed at allocate_pipes\n");
		return (NULL);
	}
	pipe_count = 0;
	while (pipe_count < 2)
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

// static void	close_remaining_pipes(int **pipefd, int cmds_i)
// {
// 	int	pipe_i;

// 	pipe_i = 0;
// 	while (pipe_i < cmds_i)
// 	{
// 	}
// }

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

// TODO
// static void	close_all_pipes(int **pipefd)
// {
// }

//２つしかパイプがなかったらうまく動かないからコマンドの分用意するべき　

int	execute_cmds(int ac, char *av[], t_pipex *pipex)
{
	int	pid;
	int	**pipefd;
	int	cmds_i;

	pipefd = allocate_pipes(ac, av);
	if (pipefd == NULL)
	{
		printf("Failed to allocate pipes\n");
		return (5);
	}
	cmds_i = 0;
	if (pipe(pipefd[0]) == -1)
		return (9);
	if (pipe(pipefd[1]) == -1)
		return (10);
	while (pipex->cmd_args[cmds_i] != NULL)
	{
		pid = fork();
		if (pid < 0)
			return (11);
		if (pid == 0)
		{
			// dup2, close, pipefdを使ったpipeの管理わけわからん
			if (cmds_i == 0)
			{
				dup2(pipex->in_fd, STDIN_FILENO);
				dup2(pipefd[0][1], STDOUT_FILENO);
			}
			else if (cmds_i == pipex->cmd_count - 1)
			{
				dup2(pipefd[(cmds_i - 1) % 2][0], STDIN_FILENO);
				dup2(pipex->out_fd, STDOUT_FILENO);
			}
			else
			{
				dup2(pipefd[(cmds_i - 1) % 2][0], STDIN_FILENO);
				dup2(pipefd[cmds_i % 2][1], STDOUT_FILENO);
			}
			close(pipex->in_fd);
			close(pipex->out_fd);
			close(pipefd[0][1]);
			close(pipefd[0][0]);
			close(pipefd[1][1]);
			close(pipefd[1][0]);
			find_and_exec(pipex, cmds_i);
			exit(127); //エラーで終了
		}
		cmds_i++;
	}
	close(pipefd[0][1]);
	close(pipefd[0][0]);
	close(pipefd[1][1]);
	close(pipefd[1][0]);
	close(pipex->in_fd);
	close(pipex->out_fd);
	while (1)
	{
		if (wait(NULL) < 0)
			break ;
	}
	// exec_retvalの値によっては、エラーを出力する必要がある。
	return (1);
}
