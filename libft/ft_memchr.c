/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:39:52 by hhikita           #+#    #+#             */
/*   Updated: 2024/11/02 14:12:39 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	c1;

	p = (unsigned char *)s;
	c1 = (unsigned char)c;
	while (n--)
	{
		if (*p == c1)
			return (p);
		p++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	s1[] = "abcdefghij";
// 	char	c;

// 	c = 'c';
// 	printf("%s\n", (char *)ft_memchr(s1, c, 3));
// 	printf("%s\n", (char *)memchr(s1, c, 3));
// 	return (0);
// }
