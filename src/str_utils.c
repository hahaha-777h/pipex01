/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:03:23 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/11 19:08:22 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	putstr_fd(const char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
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

// TODO
int	ft_strncmp(const char *s1, const char *s2, int n)
{
	if (NULL == s1 || NULL == s2 || n <= 0)
		return (0);
	while (*s1 == *s2 && *s1 != '\0' && --n)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// int	main(void)
// {
// 	const char *s1 = "aaaaabaieguwep";
// 	const char *s2 = "aaaabaieguwep";
// 	printf("%d\n", ft_strncmp(s1, s2, 5));
// 	return (0);
// }