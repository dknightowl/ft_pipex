/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:29:01 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/27 00:15:16 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
Description:
	Scans the initial n bytes of the memory area pointed to by s
	for the first instance of c. Both c and the bytes of the
	memory area pointed to by s are interpreted as unsigned char.
Return value:
	A pointer to the matching byte or NULL if the character does not
	occur in the given memory area.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s_ptr;

	s_ptr = (char *) s;
	while (n > 0)
	{
		if (*s_ptr == (char) c)
			return ((void *) s_ptr);
		s_ptr++;
		n--;
	}
	return (NULL);
}
