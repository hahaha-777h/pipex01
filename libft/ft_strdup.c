/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:14:00 by hhikita           #+#    #+#             */
/*   Updated: 2024/11/06 14:55:39 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tmp;
	size_t	len;
	char	*ans;

	len = ft_strlen(s);
	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	ans = tmp;
	while (*s)
	{
		*tmp = *s;
		tmp++;
		s++;
	}
	*tmp = '\0';
	return (ans);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	a[] = "qoghhor";
// 	char	*b1;
// 	char	*b2;

// 	b1 = strdup(a);
// 	b2 = ft_strdup(a);
// 	printf("%s\n", b1);
// 	printf("%s", b2);
// 	return (0);
// }
