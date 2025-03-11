/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:54:28 by hhikita           #+#    #+#             */
/*   Updated: 2024/10/30 16:14:39 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

// #include <string.h>

// int	main(void)
// {
// 	char	s3[] = "a";
// 	char	s4[] = "a";
// 	int		j;
// 	char	s1[] = "aaa";
// 	char	s2[] = "aaa";
// 	int		i;

// 	i = strncmp(s1, s3, 1);
// 	j = ft_strncmp(s2, s4, 1);
// 	printf("%d\n", j);
// 	printf("%d\n", j);
// 	return (0);
// }
