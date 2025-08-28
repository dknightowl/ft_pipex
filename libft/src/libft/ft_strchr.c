/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:56:40 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/27 00:15:16 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
Description:
	Returns a pointer to the first occurrence of
	the character c in the string s. Here "character
	means "byte"; this function does not work with
	wide or multibyte characters.
Return value:
	Return a pointer to the matched character or NULL
	if the character is not found. The terminating null
	byte is considered part of the string, so that if c
	is specified as '\0', these functions return a pointer
	to the terminator.
*/

char	*ft_strchr(const char *s, int c)
{
	int	n;

	n = (int) ft_strlen(s) + 1;
	while (n)
	{
		if (*s == (const char) c)
			return ((char *) s);
		s++;
		n--;
	}
	return (NULL);
}
