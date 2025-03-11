/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:25:16 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/11 19:16:05 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;
	char	*p;
	char	*ans;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	p = malloc(total_len + 1);
	if (!p)
		return (NULL);
	ans = p;
	while (*s1)
		*(p++) = *(s1++);
	while (*s2)
		*(p++) = *(s2++);
	*p = '\0';
	return (ans);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	a[] = "abcde";
// 	char	b[] = "fghi";
// 	char	*ans;

// 	ans = ft_strjoin(a, b);
// 	printf("%s", ans);
// 	return (0);
// }
