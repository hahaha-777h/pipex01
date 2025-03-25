/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:43:12 by hhikita           #+#    #+#             */
/*   Updated: 2024/11/03 17:31:40 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	int	digits;

	if (n == 0)
		return (1);
	if (n == INT_MIN)
		return (11);
	digits = 0;
	if (n < 0)
	{
		digits++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static char	*ft_strrev(char *s)
{
	size_t	len;
	size_t	i;
	char	tmp;

	i = 0;
	len = ft_strlen(s);
	while (i < (len / 2))
	{
		tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
		i++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*result;
	int		i;

	digits = ft_count_digits(n);
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	result = malloc(digits + 1);
	if (!result)
		return (NULL);
	result[digits] = '\0';
	if (n < 0)
	{
		n = -n;
		result[digits - 1] = '-';
		digits--;
	}
	i = 0;
	while (i < digits)
	{
		result[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	return (ft_strrev(result));
}

// int	main(void)
// {
// 	char	*ans;

// 	ans = ft_itoa(-567);
// 	printf("%s\n", ans);
// 	return (0);
// }
