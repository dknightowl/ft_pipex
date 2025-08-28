/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:23:52 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/27 00:15:16 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
Description:
	Compares only the first (at most) n bytes of string s1 and s2.
	The locale is not taken into account (for a locale-aware
	comparison, see strcoll(3)). The comparison is done using
	unsigned characters.
Return value:
	An integer less than, equal to, or greater than zero if s1
	(or the first n bytes thereof) is found, respectively, to be
	less than, to match, or be greater than s2.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	uc1;
	unsigned char	uc2;

	i = 0;
	while (i < n)
	{
		uc1 = (unsigned char) s1[i];
		uc2 = (unsigned char) s2[i];
		if (uc1 == '\0' || uc1 != uc2)
			return (uc1 - uc2);
		i++;
	}
	return (0);
}
