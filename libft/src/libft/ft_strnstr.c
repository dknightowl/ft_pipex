/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:03:43 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/27 00:15:16 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
Description:
	Locates the first occurrence of the null-terminated string little
	in the string big, where not more than len characters are searched.
	Characters that appear after a ‘\0’ character are not searched.
Return value:
	If little is an empty string, big is returned; if little occurs
	nowhere in big, NULL is returned; otherwise a pointer to the first
	character of the first occurrence of little is returned.
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	search_len;

	search_len = ft_strlen(little);
	if (search_len == 0)
		return ((char *) big);
	while (*big != '\0' && len >= search_len)
	{
		if (ft_strncmp(big, little, (size_t) search_len) == 0)
			return ((char *)(big));
		big++;
		len--;
	}
	return (NULL);
}
