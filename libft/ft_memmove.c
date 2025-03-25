/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:36:49 by hhikita           #+#    #+#             */
/*   Updated: 2024/11/06 11:51:40 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*d;

	if (!dest && !src)
		return (dest);
	tmp = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (d < tmp)
	{
		while (n--)
			*d++ = *tmp++;
	}
	else
	{
		d += n;
		tmp += n;
		while (n--)
			*(--d) = *(--tmp);
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	buf1[] = "qwertyu";
// 	char	buf2[] = "qwertyu";

// 	memmove(buf1, buf1 + 3, 5);
// 	ft_memmove(buf2, buf2 + 3, 5);
// 	printf("%s\n", buf1);
// 	printf("%s", buf2);
// 	return (0);
// }
