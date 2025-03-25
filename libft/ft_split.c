/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:02:59 by hhikita           #+#    #+#             */
/*   Updated: 2024/11/07 15:07:35 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			count++;
			s++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static char	*ft_strdup_v2(const char *s, char c)
{
	char	*tmp;
	size_t	len;
	char	*ans;

	len = ft_word_len(s, c);
	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	ans = tmp;
	while (*s && *s != c)
	{
		*tmp = *s;
		tmp++;
		s++;
	}
	*tmp = '\0';
	return (ans);
}

static void	ft_free_mem(char **a, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(a[j]);
		j++;
	}
	free(a);
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	size_t	word_cnt;
	size_t	i;

	word_cnt = ft_word_count(s, c);
	a = malloc((word_cnt + 1) * sizeof(char *));
	if (!a)
		return (NULL);
	a[word_cnt] = NULL;
	i = 0;
	while (i < word_cnt)
	{
		while (*s == c)
			s++;
		a[i] = ft_strdup_v2(s, c);
		if (!a[i])
		{
			ft_free_mem(a, i);
			return (NULL);
		}
		s += ft_word_len(s, c);
		i++;
	}
	return (a);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	a[] = "   111 222 333   ";
// 	size_t	i;
// 	char	**ans;

// 	ans = ft_split(a, ' ');
// 	if (!ans)
// 		return (1);
// 	for (i = 0; ans[i]; i++)
// 	{
// 		printf("%s\n", ans[i]);
// 		free(ans[i]); // 各単語のメモリを解放
// 	}
// 	free(ans); // 配列のメモリを解放
// 	i = ft_word_count(a, ' ');
// 	printf("wordcount: %zu\n", i);
// 	return (0);
// 	while (1)
// 		;
// }
