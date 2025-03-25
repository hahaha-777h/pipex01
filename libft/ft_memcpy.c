/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:17:01 by hhikita           #+#    #+#             */
/*   Updated: 2024/11/02 14:27:27 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*d;
	size_t			i;

	if (!dest && !src && n)
		return (dest);
	p = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		d[i] = p[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	buf2[] = "aaaaaaaaaa";
// 	char	buf4[] = "bbbbbbbbbb";
// 	char	buf1[] = "aaaaaaaaaa";
// 	char	buf3[] = "bbbbbbbbbb";

// 	memcpy(buf1, buf3, 0);
// 	ft_memcpy(buf2, buf4, 0);
// 	printf("%s\n%s\n", buf1, buf3);
// 	printf("%s\n%s", buf2, buf4);
// 	return (0);
// }
