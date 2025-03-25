/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:58:38 by hhikita           #+#    #+#             */
/*   Updated: 2024/11/02 19:00:40 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	c;
	size_t	len;
	char	*ans;

	c = *s1;
	while (c && ft_strchr(set, c))
		c = *(++s1);
	len = ft_strlen(s1);
	if (len)
	{
		c = *(s1 + len - 1);
		while (c && ft_strchr(set, c))
			c = *(s1 + --len - 1);
	}
	ans = (char *)malloc(len + 1);
	if (!ans)
		return (NULL);
	ft_strlcpy(ans, s1, len + 1);
	return (ans);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	a[] = "   \t  \n\n \t\t  \n\n\nt\n  ";
// 	char	b[] = " \n\t";
// 	char	*ans;

// 	ans = ft_strtrim(a, b);
// 	printf("%s", ans);
// 	return (0);
// }
