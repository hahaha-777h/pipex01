/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:54:19 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/20 16:29:32 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/* mallocした変数はすべてt_pipex *pipexに入っている*/

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

// void	cleanup(t_pipex *pipex)
// {
// }