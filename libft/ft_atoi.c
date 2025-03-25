/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:46:57 by hhikita           #+#    #+#             */
/*   Updated: 2024/11/06 14:54:09 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	num;

	num = 0;
	sign = 1;
	while ((*nptr <= '\r' && *nptr >= '\t') || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr <= '9' && *nptr >= '0')
	{
		if (sign > 0 && (LONG_MAX - (*nptr - '0')) / 10 < num)
			return ((int)LONG_MAX);
		if (sign < 0 && ((LONG_MAX - (*nptr - '0')) / 10 < num - 1))
		{
			return ((int)LONG_MIN);
		}
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)(num * sign));
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	np[] = "  -0098";
// 	int		i;
// 	int		j;

// 	i = atoi(np);
// 	j = ft_atoi(np);
// 	printf("%d\n", i);
// 	printf("%d", j);
// 	return (0);
// }
