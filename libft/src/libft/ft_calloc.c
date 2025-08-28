/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 07:21:57 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/27 00:15:16 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
Description:
	Allocates memory for an array of nmemb elements of size
	bytes each and returns a pointer to the allocated memory.
	The memory is set to zero. If nmemb or size is 0, calloc()
	returns a unique pointer value that can later be successfully
	passed to free(). If the multiplication of nmemb and size
	would result in integer overflow, then calloc() returns an
	error.
Return value:
	A pointer to the allocated memory, which is suitably aligned
	for any built-in type. On error, returns NULL. NULL may also
	be returned by a successful call to calloc() with nmemb or
	size equal to zero.
*/

static int	ft_safe_multiply(size_t a, size_t b)
{
	return (
		(a > 0 && b > 0) && (a <= INT_MAX / b) && (b <= INT_MAX / a)
	);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	else if (!ft_safe_multiply(nmemb, size))
		return (NULL);
	buffer = malloc(nmemb * size);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, nmemb * size);
	return (buffer);
}
