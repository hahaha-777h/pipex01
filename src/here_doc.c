/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:08:19 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/28 14:08:53 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static bool	get_line_and_write(t_pipex *pipex, char *deliminator)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	if (line == NULL)
	{
		free(deliminator);
		return (false);
	}
	while (ft_strcmp(line, deliminator))
	{
		if (putstr_fd(line, pipex->in_fd) == -1)
		{
			free(line);
			free(deliminator);
			return (false);
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(deliminator);
	free(line);
	return (true);
}

void	handle_here_doc(int ac, char *av[], t_pipex *pipex)
{
	static char	*filename;
	char		*deliminator;

	filename = "/tmp/temp_file_for_heredoc";
	pipex->here_doc = true;
	pipex->cmd_count--;
	pipex->in_fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->in_fd == -1)
		return ;
	deliminator = ft_strjoin(av[2], "\n");
	if (deliminator == NULL)
		return ;
	if (get_line_and_write(pipex, deliminator) == false)
		return ;
	close(pipex->in_fd);
	pipex->in_fd = open(filename, O_RDONLY);
	pipex->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
}
