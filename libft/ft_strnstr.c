/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:15:39 by hhikita           #+#    #+#             */
/*   Updated: 2024/11/02 18:51:52 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (!*little)
		return ((char *)(big));
	little_len = ft_strlen(little);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		if (i + little_len <= len && !ft_strncmp(&big[i], little, little_len))
			return ((char *)(&big[i]));
		i++;
	}
	return (NULL);
}
