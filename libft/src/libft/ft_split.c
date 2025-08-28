/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:12:39 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/27 00:15:16 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
Description:
	Allocates memory (using malloc(3)) and returns an
	array of strings obtained by splitting ’s’ using
	the character ’c’ as a delimiter. The array must
	end with a NULL pointer.
Return value:
	The array of new strings resulting from the split.
	NULL if the allocation fails.
*/

/* Extracts next word in the string */
static char	*ft_next_word(char const *s, int starti, int word_len)
{
	char	*word;
	int		i;

	word = (char *) malloc(word_len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < word_len)
	{
		word[i] = s[starti + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

/* Finds length of next word */
static int	ft_nword_len(char const *s, char c)
{
	int	word_len;

	word_len = 0;
	while (s[word_len] != '\0' && s[word_len] != c)
		word_len++;
	return (word_len);
}

/* Finds num. of words in the string */
static int	ft_word_count(char const *s, char c)
{
	int	count;
	int	idx;

	count = 0;
	idx = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] != c)
		{
			count++;
			idx += ft_nword_len(s + idx, c);
		}
		else
			idx++;
	}
	return (count);
}

/* Frees array */
static void	ft_free_arr(char **arr, int size)
{
	while (size)
	{
		free(arr[size]);
		size--;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**s_arr;
	int		w_i;
	int		b_i;

	s_arr = (char **) malloc((ft_word_count(s, c) + 1) * sizeof(char *));
	if (!s_arr)
		return (NULL);
	w_i = 0;
	b_i = 0;
	while (s[b_i] != '\0')
	{
		if (s[b_i] != c)
		{
			s_arr[w_i] = ft_next_word(s, b_i, ft_nword_len(s + b_i, c));
			if (!(s_arr[w_i]))
				return (ft_free_arr(s_arr, w_i - 1), NULL);
			w_i++;
			b_i += ft_nword_len(s + b_i, c);
		}
		else
			b_i++;
	}
	s_arr[w_i] = NULL;
	return (s_arr);
}
