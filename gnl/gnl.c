/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:57:49 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/10 18:32:08 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

static char	*ft_read_str(int fd, char *str)
{
	ssize_t	check_read;
	char	read_str[BUFFER_SIZE + 1];
	char	*tmp;

	while (1)
	{
		check_read = read(fd, read_str, BUFFER_SIZE);
		if (check_read == -1)
			return (NULL);
		if (check_read == 0)
			return (str);
		read_str[check_read] = '\0';
		tmp = ft_strjoin(str, read_str);
		free(str);
		if (!tmp)
			return (NULL);
		str = tmp;
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (str);
}

static char	*ft_get_line(char *str)
{
	char	*line;
	int		len;

	if (!str)
		return (NULL);
	if (!*str)
	{
		free(str);
		return (NULL);
	}
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	line = ft_substr(str, 0, len);
	return (line);
}

static char	*ft_update_str(char *str, char *line)
{
	char	*new_str;
	size_t	str_len;
	size_t	line_len;

	if (!str || !line)
		return (NULL);
	str_len = ft_strlen(str);
	line_len = ft_strlen(line);
	new_str = ft_substr(str, line_len, str_len - line_len);
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str || !ft_strchr(str, '\n'))
		str = ft_read_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	if (!line)
		return (NULL);
	str = ft_update_str(str, line);
	return (line);
}

// #include <stdio.h>

// int	main(int ac, char *av[])
// {
// 	char	*line;

// 	line = get_next_line(0);
// 	printf("av[2]:%s\nline:%s", av[2], line);
// 	return (0);
// }
