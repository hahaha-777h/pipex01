/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:03:23 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/27 15:29:22 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	putstr_fd(const char *s, int fd)
{
	if (s == NULL || fd < 0)
		return (0);
	write(fd, s, ft_strlen(s));
	return (0);
}

// Do not pass NULL as argument!!!
int	ft_strcmp(char *s1, char *s2)
{
	if (NULL == s1 || NULL == s2)
		return (0);
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// int	main(void)
// {
// 	const char *s1 = "aaa\n";
// 	const char *s2 = "bbbbbb\n";
// 	printf("%d\n", ft_strncmp(s1, s2, 5));
// 	putstr_fd(s1, STDOUT_FILENO);
// 	putstr_fd(s2, STDOUT_FILENO);
// 	return (0);
// }