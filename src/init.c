/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:49:40 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/18 15:27:54 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	init_pipex(int ac, t_pipex *pipex)
{
	pipex->in_fd = STDIN_FILENO;
	pipex->out_fd = STDOUT_FILENO;
	pipex->here_doc = false;
	pipex->is_valid_arg = true;
	// pipex->is_valid_infile = true;
	pipex->is_envp = true;
	pipex->cmd_paths = NULL;
	pipex->cmd_args = NULL;
	if (pipex->here_doc == false)
		pipex->cmd_count = ac - NON_CMD_ARGC;
	else
		pipex->cmd_count = ac - NON_CMD_ARGC - 1;
}
