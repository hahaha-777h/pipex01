/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:25:51 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/25 19:12:54 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_and_dup_first(t_pipex *pipex, int **pipefd)
{
	close(pipex->out_fd);
	close(pipefd[0][0]);
	dup2(pipex->in_fd, STDIN_FILENO);
	dup2(pipefd[0][1], STDOUT_FILENO);
	close(pipefd[0][1]);
	close(pipex->in_fd);
}

void	close_and_dup_middle(t_pipex *pipex, int **pipefd, int cmds_i)
{
	close(pipex->in_fd);
	close(pipex->out_fd);
	close(pipefd[cmds_i - 1][1]);
	close(pipefd[cmds_i][0]);
	dup2(pipefd[cmds_i - 1][0], STDIN_FILENO);
	dup2(pipefd[cmds_i][1], STDOUT_FILENO);
	close(pipefd[cmds_i - 1][0]);
	close(pipefd[cmds_i][1]);
}

void	close_and_dup_last(t_pipex *pipex, int **pipefd, int cmds_i)
{
	close(pipex->in_fd);
	close(pipefd[cmds_i - 1][1]);
	dup2(pipefd[cmds_i - 1][0], STDIN_FILENO);
	dup2(pipex->out_fd, STDOUT_FILENO);
	close(pipex->out_fd);
	close(pipefd[cmds_i - 1][0]);
}
