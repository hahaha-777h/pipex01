/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:53:33 by hhikita           #+#    #+#             */
/*   Updated: 2024/10/27 12:40:07 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	size_t	a_len;
	char	*p;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_strdup(""));
	if (s_len - start < len)
		a_len = s_len - start;
	else
		a_len = len;
	p = malloc(a_len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < a_len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char const		a[] = "asdfghjkl";
// 	unsigned int	s;
// 	char			*ans;

// 	s = 'h';
// 	ans = ft_substr(a, s, 3);
// 	printf("%s", ans);
// 	return (0);
// }
