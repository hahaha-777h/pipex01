/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:57:40 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/18 17:23:11 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	**allocate_pipes(int ac, char *av[], t_pipex *pipex)
{
	int	**pipefd;
	int	pipe_count;

	(void)ac;
	(void)av;
	pipefd = (int **)malloc((pipex->cmd_count + 1) * sizeof(int *));
	if (pipefd == NULL)
	{
		printf("malloc1 failed at allocate_pipes\n");
		return (NULL);
	}
	pipefd[pipex->cmd_count] = NULL;
	pipe_count = 0;
	while (pipe_count != pipex->cmd_count)
	{
		pipefd[pipe_count] = (int *)malloc(2 * sizeof(int));
		if (pipefd[pipe_count] == NULL)
		{
			printf("malloc2 failed at allocate_pipes\n");
			return (NULL);
		}
		pipe_count++;
	}
	return (pipefd);
}

static void	close_pipefd(int **pipefd, int cmds_i)
{
	int	pipe_i;

	pipe_i = 0;
	while (pipe_i < cmds_i)
	{
		close(pipefd[pipe_i][0]);
		close(pipefd[pipe_i][1]);
		pipe_i++;
	}
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
		path_i++;
	}
	printf("exec failed at find_and_exec\n");
	return (127);
}

int	execute_cmds(int ac, char *av[], t_pipex *pipex)
{
	int	pid;
	int	**pipefd;
	int	cmds_i;
	int	exec_retval;

	pipefd = allocate_pipes(ac, av, pipex);
	if (pipefd == NULL)
	{
		printf("Failed to allocate pipes\n");
		return (5);
	}
	cmds_i = 0;
	exec_retval = 0;
	// これ危ないかも　（親プロセスでdup2すると全てに反映されるから）
	// dup2(pipex->in_fd, STDIN_FILENO);
	// dup2(pipex->out_fd, STDOUT_FILENO);
	while (pipex->cmd_args[cmds_i] != NULL)
	{
		pipe(pipefd[cmds_i]);
		pid = fork();
		if (pid == 0)
		{
			if (cmds_i != 1)
				dup2(pipefd[cmds_i - 1][0], pipex->in_fd);
			dup2(pipefd[cmds_i][1], STDOUT_FILENO);
			if (cmds_i == pipex->cmd_count - 1)
				dup2(pipex->out_fd, STDOUT_FILENO);
			exec_retval = find_and_exec(pipex, cmds_i);
			close_pipefd(pipefd, cmds_i);
		}
		else
			close_pipefd(pipefd, cmds_i);
		cmds_i++;
	}
	return (exec_retval);
}

/*
			***execute_cmds()を確認する関数***
	1.t_pipex pipexを設定する
	2.かんたんなコマンドを渡して実行させてみる。

*/

// int	main(int ac, char *av[], char **envp)
// {
// 	int exec_val;
// 	t_pipex pipex;
// 	init_pipex(&pipex);
// 	pipex.cmd_args = get_cmds(ac, av, &pipex);
// 	pipex.cmd_paths = get_path(envp);
// 	exec_val = 0;

// 	exec_val = execute_cmds(ac, av, &pipex);
// 	printf("exec_val:%d\n", exec_val);
// 	return (exec_val);
// }