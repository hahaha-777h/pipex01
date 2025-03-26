/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:02:59 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/26 14:13:04 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**malloc_tokens(char const *s, char c, size_t *token_count)
{
	char	**tokens;

	*token_count = 0;
	while (*s == c)
		s++;
	if (*s == '\0')
		return (NULL);
	while (*s)
	{
		if (*s != c)
			*token_count = *token_count + 1;
		while (*s && (*s != c))
			s++;
		while (*s && (*s == c))
			s++;
	}
	tokens = malloc((*token_count + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	tokens[*token_count] = NULL;
	return (tokens);
}

static void	free_2d(char **arr)
{
	size_t	row_i;

	if (arr == NULL)
		return ;
	row_i = 0;
	while (arr[row_i])
	{
		free(arr[row_i]);
		row_i++;
	}
	free(arr);
}

static size_t	next_word_len(char const *s, char c)
{
	size_t	word_len;

	word_len = 0;
	if (!s || !*s)
		return (-1);
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		s++;
		word_len++;
	}
	return (word_len);
}

static char	*copy_and_split(char const *s, char c, size_t word_len)
{
	char	*token;
	size_t	char_pos;

	token = malloc((word_len + 1) * sizeof(char));
	if (token == NULL)
	{
		free(token);
		return (NULL);
	}
	token[word_len] = '\0';
	char_pos = 0;
	while (char_pos < word_len)
	{
		token[char_pos] = s[char_pos];
		char_pos++;
	}
	return (token);
}

char	**ft_split(char const *s, char c)
{
	char	**tokens;
	size_t	token_count;
	size_t	pos;
	size_t	word_len;

	tokens = malloc_tokens(s, c, &token_count);
	if (tokens == NULL)
		return (NULL);
	pos = 0;
	while (pos < token_count)
	{
		word_len = next_word_len(s, c);
		tokens[pos] = copy_and_split(s, c, word_len);
		if (tokens[pos] == NULL)
		{
			free_2d(tokens);
			return (NULL);
		}
		s += word_len;
		while (*s && *s == c)
			s++;
		pos++;
	}
	return (tokens);
}

// int	main(int ac, char **av)
// {
// 	int row;

// 	(void)ac;
// 	char **arr;
// 	arr = ft_split(av[1], av[2][0]);
// 	if (arr == NULL)
// 		return (1);
// 	if (*arr == NULL)
// 		return (2);
// 	row = 0;
// 	while (arr[row])
// 	{
// 		printf("row:%d, %s\n", row, arr[row]);
// 		row++;
// 	}
// 	return (0);
// }