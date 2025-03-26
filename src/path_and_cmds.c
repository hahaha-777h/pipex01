/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_and_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:08:50 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/26 14:25:51 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	**add_slash(char **split_path)
{
	int		path_i;
	char	*path_with_slash;

	path_i = 0;
	while (split_path[path_i])
	{
		path_with_slash = ft_strjoin(split_path[path_i], "/");
		if (path_with_slash == NULL)
			return (NULL);
		free(split_path[path_i]);
		split_path[path_i] = path_with_slash;
		path_i++;
	}
	return (split_path);
}

char	**get_path(char **envp)
{
	char	*path;
	char	**split_path;
	int		path_row;

	path_row = 0;
	if (envp == NULL)
		return (NULL);
	while (envp[path_row])
	{
		if (!ft_strncmp(envp[path_row], "PATH=", 5))
			break ;
		path_row++;
	}
	if (envp[path_row] == NULL)
		return (NULL);
	path = ft_substr(envp[path_row], 5, ft_strlen(envp[path_row]) - 5);
	if (path == NULL)
		return (NULL);
	split_path = ft_split(path, ':');
	free(path);
	if (split_path == NULL)
		return (NULL);
	return (add_slash(split_path));
}

char	***get_cmds(int ac, char *av[], t_pipex *pipex)
{
	int		arg_i;
	int		cmd_i;
	char	***cmds;

	arg_i = CMD_START_POSITION;
	if (pipex->here_doc == true)
		arg_i++;
	cmds = malloc((ac - arg_i) * sizeof(char **));
	if (cmds == NULL)
		return (NULL);
	cmds[ac - arg_i - 1] = NULL;
	cmd_i = 0;
	while (arg_i < (ac - 1))
	{
		cmds[cmd_i] = ft_split(av[arg_i], ' ');
		if (cmds[cmd_i] == NULL)
		{
			free_3d(cmds);
			return (NULL);
		}
		cmd_i++;
		arg_i++;
	}
	return (cmds);
}
