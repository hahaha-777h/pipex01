/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:22:00 by hhikita           #+#    #+#             */
/*   Updated: 2024/11/06 14:56:05 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			src_len;
	unsigned int	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

// int	main(void)
// {
// 	char	buf1[] = "aaaaaaaa";
// 	char	buf2[] = "bbbbbbbb";
// 	int		a;

// 	a = (int)ft_strlcpy(buf1, buf2, 5);
// 	printf("%d:%s\n", a, buf1);
// 	return (0);
// }
