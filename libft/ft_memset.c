/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:13:55 by hhikita           #+#    #+#             */
/*   Updated: 2024/11/02 12:22:32 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*buf2;
// 	char	*buf1;

// 	buf1 = NULL;
// 	buf2 = NULL;
// 	memset(buf1, '1', 10);
// 	ft_memset(buf2, '1', 10);
// 	printf("%s\n", buf1);
// 	printf("%s\n", buf2);
// 	return (0);
// }
