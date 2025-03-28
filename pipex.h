/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:37:45 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/28 14:09:06 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define NON_CMD_ARGC 3
# define CMD_START_POSITION 2

# include "gnl/gnl.h"
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h> //open
# include <stdbool.h>
# include <stdio.h>  //perror
# include <stdlib.h> //malloc free
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	bool	here_doc;
	bool	is_valid_arg;
	char	**cmd_paths;
	char	***cmd_args;
	int		cmd_count;

}			t_pipex;

// init

void		init_pipex(int ac, t_pipex *pipex);

// str_utils

int			putstr_fd(const char *s, int fd);
int			ft_strcmp(char *s1, char *s2);

// prepare for execution

char		**get_path(char **envp);
char		***get_cmds(int ac, char *av[], t_pipex *pipex);

// exec

int			execute_cmds(t_pipex *pipex);

// cleanup

void		free_pipes(t_pipex *pipex, int **pipefd);
void		cleanup(t_pipex *pipex);
void		free_3d(char ***arr3d);

// handle_cmd

void		close_and_dup_first(t_pipex *pipex, int **pipefd);
void		close_and_dup_middle(t_pipex *pipex, int **pipefd, int cmds_i);
void		close_and_dup_last(t_pipex *pipex, int **pipefd, int cmds_i);

// here_doc

void		handle_here_doc(int ac, char *av[], t_pipex *pipex);

#endif