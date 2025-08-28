/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:49:10 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/28 15:42:57 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
	@brief Calculates the length of the hexadecimal
	string from the given unsigned integer

	@param uint_n The unsigned integer to be used to calculate
	the length from

	@return The length of the hexadecimal string
*/
static size_t	ft_hexlen(unsigned int uint_n)
{
	if (uint_n > 15)
		return (ft_hexlen(uint_n / 16) + ft_hexlen(uint_n % 16));
	return (1);
}

/**
	@brief Fills the given buffer with the hexadecimal
	value calculated from the given unsigned integer.
	Lowercase hexadecimal is used.

	@param n Unsigned integer to calculate the
	hexadecimal value from
	@param buffer Buffer to fill the hexadecimal string
	with
	@param hlen The length of the hexadecimal string
	@param is_upper Flag to determine whether to use
	upper or lowercase hex digits

	@return None.
*/
void	ft_fill_hexbuf(unsigned int n, char *buffer,\
	size_t hlen, t_char_case c_case)
{
	size_t	idx;

	idx = hlen;
	buffer[idx--] = '\0';
	if (!n)
		buffer[idx] = '0';
	else
	{
		while (n)
		{
			if (c_case == UPPERCASE)
				buffer[idx] = UPPERCASE_HEX_DIGITS[n % 16];
			else
				buffer[idx] = LOWERCASE_HEX_DIGITS[n % 16];
			n /= 16;
			idx--;
		}
	}
}

/**
	@brief Converts an unsigned integer to an
	unsigned lowercase hexadecimal string

	@param uint_n Unsigned integer to be converted
	@param is_upper Determines whether to use uppercase
	in the conversion

	@return The converted string, or NULL upon error
*/
char	*ft_utohex(unsigned int uint_n, t_char_case is_upper)
{
	char			*hex_buffer;
	size_t			hex_len;

	hex_len = ft_hexlen(uint_n);
	hex_buffer = malloc((hex_len + 1) * sizeof(char));
	if (!hex_buffer)
		return (NULL);
	ft_fill_hexbuf(uint_n, hex_buffer, hex_len, is_upper);
	return (hex_buffer);
}
