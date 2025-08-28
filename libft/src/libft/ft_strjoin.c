/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:48:43 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/27 00:15:16 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
Description:
	Allocates memory (using malloc(3)) and returns a
	new string, which is the result of concatenating
	’s1’ and ’s2’.
Return value:
	The new string. NULL if the allocation fails.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	s1_len;
	size_t	s2_len;
	size_t	idx;

	s1_len = ft_strlen((char *) s1);
	s2_len = ft_strlen((char *) s2);
	s = (char *) malloc(s1_len + s2_len + 1);
	if (!s)
		return (NULL);
	idx = 0;
	while (idx < s1_len)
	{
		s[idx] = s1[idx];
		idx++;
	}
	while ((idx - s1_len) < s2_len)
	{
		s[idx] = s2[idx - s1_len];
		idx++;
	}
	s[idx] = '\0';
	return (s);
}
