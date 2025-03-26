/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:49:40 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/26 14:50:51 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	init_pipex(int ac, t_pipex *pipex)
{
	pipex->in_fd = STDIN_FILENO;
	pipex->out_fd = STDOUT_FILENO;
	pipex->here_doc = false;
	pipex->is_valid_arg = true;
	pipex->cmd_paths = NULL;
	pipex->cmd_args = NULL;
	pipex->cmd_count = ac - NON_CMD_ARGC;
}
