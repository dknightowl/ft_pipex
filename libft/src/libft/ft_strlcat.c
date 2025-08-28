/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 09:32:13 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/27 00:15:16 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
Description:
	Appends the NUL-terminated string src to the end of dst.
	It will append at most size - strlen(dst) - 1 bytes,
	NUL-terminating the result. Takes the full size of the buffer
	(not just the length) and guarantee to NUL-terminate the
	result (as long as there is at least one byte free in dst).
	Note that a byte for the NUL should be included in size
Return value:
	The initial length of dst plus the length of src. However, if
	strlcat() traverses size characters without finding a NUL,
	the length of the string is considered to be size and
	the destination string will not be NUL-terminated (since there
	was no space for the NUL)
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_strlen;
	size_t	src_strlen;
	size_t	i;

	dst_strlen = ft_strlen(dst);
	src_strlen = ft_strlen(src);
	if (dstsize <= dst_strlen)
		return (src_strlen + dstsize);
	i = 0;
	while (i < (dstsize - dst_strlen - 1) && src[i] != '\0')
	{
		dst[dst_strlen + i] = src[i];
		i++;
	}
	dst[dst_strlen + i] = '\0';
	return (src_strlen + dst_strlen);
}
