/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:37:45 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/11 12:58:52 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define NON_CMD_ARGC 3 // unused
# define CMD_START_POSITION 2

# include "gnl/gnl.h"
# include <errno.h>
# include <fcntl.h> //open
# include <stdbool.h>
# include <stdio.h>  //perror
# include <stdlib.h> //malloc free
# include <string.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	bool	here_doc;
	bool	is_valid_arg;
	bool	is_envp;
	// bool	is_valid_infile;
	char	**cmd_paths;
	char	***cmd_args;
	int		cmd_count;

}			t_pipex;

// init

void		init_pipex(t_pipex *pipex);
// str_utils

void		putstr_fd(const char *s, int fd);
int			ft_strcmp(char *s1, char *s2);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, int n);

// split
char		**ft_split(char const *s, char c);

// prepare for execution

char		**get_path(char **envp);
char		***get_cmds(int ac, char *av[], t_pipex *pipex);
#endif