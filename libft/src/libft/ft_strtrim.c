/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:12:26 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/27 00:15:16 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
Destination:
	Allocates memory (using malloc(3)) and returns a copy of ’s1’
	with characters from ’set’ removed from the beginning and the
	end.
Return value:
	The trimmed string or NULL, if allocation fails
*/

static int	ft_totrim(char const c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		strlen;
	int		starti;
	int		endi;
	char	*trimmed_s;

	strlen = (int) ft_strlen(s1);
	if (strlen == 0)
		return (ft_strdup(""));
	starti = 0;
	endi = strlen - 1;
	while (ft_totrim(s1[starti], set))
		starti++;
	while (ft_totrim(s1[endi], set) && endi >= starti)
		endi--;
	trimmed_s = ft_substr(s1, starti, (endi - starti + 1));
	return (trimmed_s);
}
