/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:54:19 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/25 13:45:58 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_pipes(t_pipex *pipex, int **pipefd)
{
	int	pipe_i;

	pipe_i = 0;
	while (pipe_i < pipex->cmd_count - 1)
	{
		free(pipefd[pipe_i]);
		pipe_i++;
	}
	free(pipefd);
}

static void	free_2d(char **arr)
{
	size_t	row_i;

	if (arr == NULL)
		return ;
	row_i = 0;
	while (arr[row_i])
	{
		free(arr[row_i]);
		row_i++;
	}
	free(arr);
}

void	free_3d(char ***arr3d)
{
	size_t	arr_i;

	arr_i = 0;
	while (arr3d[arr_i])
	{
		free_2d(arr3d[arr_i]);
		arr_i++;
	}
	free(arr3d);
}

void	cleanup(t_pipex *pipex)
{
	close(pipex->in_fd);
	close(pipex->out_fd);
	if (pipex->cmd_paths != NULL)
		free_2d(pipex->cmd_paths);
	free_3d(pipex->cmd_args);
}
