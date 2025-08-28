/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:10:10 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/27 00:15:16 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
Description:
	Returns a pointer to the last occurrence of the character c in
	the string s. Here "character" means "byte".
Return value:
	A pointer to the matched character or NULL if the character is
	not found. The terminating null byte is considered part of the
	string, so that if c is specified as '\0', these functions
	return a pointer to the terminator.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*last_c;
	int		n;

	last_c = NULL;
	n = (int) ft_strlen(s) + 1;
	while (n)
	{
		if (*s == (const char) c)
			last_c = (char *) s;
		s++;
		n--;
	}
	return (last_c);
}
