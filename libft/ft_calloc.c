/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:18:29 by hhikita           #+#    #+#             */
/*   Updated: 2024/10/30 16:21:01 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size != 0 && (SIZE_MAX / size < nmemb))
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		p = malloc(0);
		return (p);
	}
	p = malloc(size * nmemb);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}

// #include <stdio.h>

// int	main(void)
// {
// 	size_t	nmemb;
// 	size_t	size;
// 	char	*p;

// 	nmemb = 0;
// 	size = 5;
// 	p = (char *)ft_calloc(nmemb, size);
// 	// for (int i = 0; i < 10; i++)
// 	// 	printf("%d\n", p[i]);
// 	printf("%p\n", p);
// 	return (0);
// }
