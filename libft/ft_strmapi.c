/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:47:51 by hhikita           #+#    #+#             */
/*   Updated: 2024/10/27 14:34:47 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	f(unsigned int i, char a)
// {
// 	(void)i;
// 	return (a + 1);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*p;

	if (!s || !f)
		return (NULL);
	len = (unsigned int)ft_strlen(s);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[len] = '\0';
	return (p);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*ans;
// 	char	a[] = "abcdefg";

// 	ans = ft_strmapi(a, f);
// 	printf("%s\n", ans);
// 	return (0);
// }
