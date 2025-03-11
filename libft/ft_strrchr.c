/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:41:22 by hhikita           #+#    #+#             */
/*   Updated: 2024/11/06 11:34:03 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)last);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	buf1[] = "wegaiohoawahi";
// 	char	buf2[] = "wegaiohoawhai";
// 	char	c;
// 	char	*p1;
// 	char	*p2;

// 	c = 'a';
// 	p1 = ft_strrchr(buf1, '\0');
// 	p2 = strrchr(buf2, '\0');
// 	printf("%p\n", p1);
// 	printf("%p", p2);
// 	return (0);
// }
