/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:01:19 by hhikita           #+#    #+#             */
/*   Updated: 2024/10/30 16:21:12 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char	buf1[] = "aaaaaaaa";
// 	char	buf2[] = "aaaaaaaa";

// 	bzero(buf1, 5);
// 	ft_bzero(buf2, 5);
// 	for (int i = 0; i < 8; i++)
// 	{
// 		printf("%d", buf1[i]);
// 	}
// 	printf("\n");
// 	for (int i = 0; i < 8; i++)
// 	{
// 		printf("%d", buf2[i]);
// 	}
// 	return (0);
// }
