/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 09:32:30 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/27 00:15:16 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
Description:
	Copies up to size - 1 characters from the NUL-terminated string
	src to dst, NUL-terminating the result. Both src and dst must be
	NUL-terminated. Take the full size of the buffer (not just the
	length) and guarantee to NUL-terminate the result (as long as
	size is larger than 0
Return value:
	Total length of the src string
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	o_size;

	src_len = ft_strlen(src);
	o_size = size;
	while (size > 1 && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	if (o_size > 0)
		*dst = '\0';
	return (src_len);
}
