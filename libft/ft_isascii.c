/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:54:23 by hhikita           #+#    #+#             */
/*   Updated: 2024/10/30 16:20:48 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c <= 127 && c >= 0);
}
// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", isascii('	'));
// 	printf("%d", ft_isascii('	'));
// 	return (0);
// }
