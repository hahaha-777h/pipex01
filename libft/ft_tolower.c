/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:18:20 by hhikita           #+#    #+#             */
/*   Updated: 2024/10/30 16:12:56 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c <= 'Z' && c >= 'A')
		c = c - 'A' + 'a';
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%c", tolower('A'));
// 	printf("\n%c", ft_tolower('A'));
// 	return (0);
// }
