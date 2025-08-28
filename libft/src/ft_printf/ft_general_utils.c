/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 11:55:54 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/28 15:42:57 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
===============================================
	General utility functions for ft_printf
===============================================
*/

/**
	@brief Frees all pointer arguments in the order it is specified.

	@param ptr1 First, compulsory pointer argument to be freed
	@param ... Any number of pointer arguments to be freed as well

	@return None.
*/
void	ft_free_all(void *ptr1, ...)
{
	va_list	args;
	void	*ptr;

	va_start(args, ptr1);
	ptr = ptr1;
	while (ptr)
	{
		free(ptr);
		ptr = va_arg(args, void *);
	}
	va_end(args);
}

/**
	@brief Creates a new string for padding purposes

	@param pad_char The character to be used in padding
	@param len The length of the padding string needed

	@return Newly-created null-terminated padding.
	E.g. pad_char='0' and char=3 returns "000"
*/
char	*ft_new_padding(char pad_char, int len)
{
	char	*padding;

	padding = (char *) malloc(len + 1);
	if (!padding)
		return (NULL);
	ft_memset(padding, pad_char, len);
	padding[len] = '\0';
	return (padding);
}

/**
	@brief Returns the index of the character in the string
	if it exists.

	@param c Character to search for
	@param s String to search in for character c

	@return Index of character if found. If not found, -1
*/
int	ft_idxof_c(const char c, const char *s)
{
	int	idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == c)
			return (idx);
		idx++;
	}
	return (IDX_NOT_FOUND);
}

/**
	@brief Converts a character to string

	@param c The character to be converted

	@return The converted string, or NULL if an error occurred
*/
char	*ft_ctoa(int c)
{
	char	*output_s;

	output_s = malloc(2);
	if (!output_s)
		return (NULL);
	output_s[0] = (char) c;
	output_s[1] = '\0';
	return (output_s);
}
