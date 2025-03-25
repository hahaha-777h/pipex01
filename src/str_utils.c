/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:03:23 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/25 14:00:41 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	putstr_fd(const char *s, int fd)
{
	if (s == NULL || fd < 0)
		return (0);
	if (*s != '\0')
	{
		if (write(fd, s, 1) < 0)
			return (-1);
		putstr_fd(s + 1, fd);
	}
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
// 	const char *s1 = "aaaaabaieguwep";
// 	const char *s2 = "aaaabaieguwep";
// 	printf("%d\n", ft_strncmp(s1, s2, 5));
// 	return (0);
// }