/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:25:33 by hhikita           #+#    #+#             */
/*   Updated: 2024/11/06 11:33:59 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	buf1[] = "wegiohoawhi";
// 	char	buf2[] = "wegiohoawhi";
// 	char	c;
// 	char	*p1;
// 	char	*p2;

// 	c = 'a';
// 	p1 = ft_strchr(buf1, '\0');
// 	p2 = strchr(buf2, '\0');
// 	printf("%p\n", p1);
// 	printf("%p", p2);
// 	return (0);
// }
