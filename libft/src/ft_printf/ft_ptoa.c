/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:04:29 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/28 15:42:57 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
	@brief Fills the provided buffer with the pointer value

	@param ptr The pointer value to fill the buffer with
	@param buffer The buffer to contain the pointer value
	@param buffer_size The size of the buffer

	@return None.
*/
static void	ft_fill_addrbuffer(uintptr_t ptr, char *buffer, int buffer_size)
{
	int	idx;

	buffer[0] = '0';
	buffer[1] = 'x';
	idx = buffer_size - 1;
	buffer[idx--] = '\0';
	while (ptr)
	{
		buffer[idx] = LOWERCASE_HEX_DIGITS[ptr % 16];
		ptr /= 16;
		idx--;
	}
}

/**
	@brief Calculates and returns the length of the hexidecimal
	obtained from the given unsigned long value

	@param ulong_n Unsigned long value to calculate the hexadecimal
	length from

	@return Length of hexadecimal value for the unsigned long value
*/
static size_t	ft_hexlen(unsigned long ulong_n)
{
	if (ulong_n > 15)
		return (ft_hexlen(ulong_n / 16) + ft_hexlen(ulong_n % 16));
	return (1);
}

/**
	@brief Converts a pointer value to a hexadecimal
	address string

	@param ptr Pointer with address to be converted

	@return Converted address string or NULL on error
*/
char	*ft_ptoa(const void *ptr)
{
	size_t	addr_size;
	char	*addr_buffer;

	if (ptr)
	{
		addr_size = 2 + ft_hexlen((uintptr_t) ptr) + 1;
		addr_buffer = malloc(addr_size);
		if (!addr_buffer)
			return (NULL);
		ft_fill_addrbuffer((uintptr_t) ptr, addr_buffer, addr_size);
		return (addr_buffer);
	}
	return (ft_calloc(1, 1));
}
