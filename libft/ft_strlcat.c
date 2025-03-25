/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:08:34 by hhikita           #+#    #+#             */
/*   Updated: 2024/11/03 15:28:28 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (src_len + size);
	while (dst_len + i < size - 1 && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*buf3;
// 	char	buf4[] = "cccc";
// 	int		j;

// 	buf3 = NULL;
// 	// char	buf1[] = "aaaa";
// 	// char	buf2[] = "bbbb";
// 	// int		i;
// 	// i = strlcat(buf1, buf2, 2);
// 	j = ft_strlcat(buf3, buf4, 0);
// 	// printf("%s:%d", buf1, i);
// 	printf("%s:%d", buf3, j);
// 	return (0);
// }
