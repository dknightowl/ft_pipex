/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:44:53 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/27 00:15:16 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
Description:
	Copies n bytes from memory area src to memory area dest.
	The memory areas may overlap: copying takes place as though
	the bytes in src are first copied into a temporary array that
	does not overlap src or dest, and the bytes are then copied
	from the temporary array to dest.
Return value:
	Pointer to dest
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_ptr;
	const char	*src_ptr;

	dest_ptr = (char *) dest;
	src_ptr = (const char *) src;
	if (dest < src)
	{
		while (n)
		{
			*dest_ptr++ = *src_ptr++;
			n--;
		}
	}
	else
	{
		src_ptr += (n - 1);
		dest_ptr += (n - 1);
		while (n)
		{
			*dest_ptr-- = *src_ptr--;
			n--;
		}
	}
	return (dest);
}
