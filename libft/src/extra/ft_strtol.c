/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:35:55 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/27 16:55:01 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra.h"

/**
	@brief Parse and resolve sign of a number from a string. This helper
	function checks for an optional leading '+' or '-' character. If a sign
	is found, `strptr` is advanced past it.

	@param strptr The point to the current position in the string that is being
	parsed

	@return Sign of number. If '-' was found, -1. Otherwise, 1.
*/
static int	resolve_sign(const char **strptr)
{
	int	sign;

	sign = 1;
	if (*(*strptr) == '-' || *(*strptr) == '+')
	{
		if (*(*strptr) == '-')
			sign = -1;
		(*strptr)++;
	}
	return (sign);
}

/**
	@brief Determines the numerical base for string-to-long conversion and
	skips over detected base prefixes.
	- If `base` == 0, it automatically detects the base from the string:
		- "0x" or "0X" prefix implies base 16 (hexadecimal)
		- "0x" prefix implies base 8 (octal)
		- Otherwise, base 10 (decimal) is used
	- If `base` is explicitly 16, it checks for and skips an "0x" or "0X" prefix

	@param strptr Pointer to the current position in the string to advanced if
	a base prefix is detected
	@param base The initial base provided for the conversion. If 0, the base is
	determined automatically

	@return The resolved numerical base to be used for conversion
*/
static int	resolve_base(const char **strptr, int base)
{
	if (base == 0)
	{
		if (*(*strptr + 1) == 'x' || *(*strptr + 1) == 'X')
		{
			base = 16;
			(*strptr) += 2;
		}
		else if (**strptr == '0')
		{
			base = 8;
			(*strptr) += 1;
		}
		else
			base = 10;
	}
	else if (base == 16)
	{
		if (**strptr == '0' && (*(*strptr + 1) == 'x' || *(*strptr) == 'X'))
			(*strptr) += 2;
	}
	return (base);
}

static int	resolve_digit(const char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	else if (ft_islower(c))
		return (c - 'a' + 10);
	else if (ft_isupper(c))
		return (c - 'A' + 10);
	else
		return (-1);
}

/**
	@brief Custom implementation strtol. Converts string to long int

	@param str Pointer to null-terminated byte string to be interpreted
	that represents an integral number
	@param endptr Pointer to an object of type `char` - whose value is set by
	the function to the next character in str after the numerical value; Can
	also be a null pointer - in which case it is not used
	@param base Numerical base (radix) that determines the valid characters
	and their interpretation; If this is 0, based used it determined by the
	format in the sequence.

	@return Upon success, returns the converted integral number as a long int.
	If no valid conversion could be performed, a zero value is returned (0L).
*/
long	ft_strtol(const char *str, char **endptr, int base)
{
	const char	*strptr;
	long		result;
	int			sign;
	int			digit;

	strptr = str;
	result = 0;
	sign = 1;
	while (*strptr == ' ' || (*strptr >= 9 && *strptr <= 13))
		strptr++;
	sign = resolve_sign(&strptr);
	base = resolve_base(&strptr, base);
	while (1)
	{
		digit = resolve_digit(*strptr);
		if (digit >= base || digit == -1)
			break ;
		result *= base;
		result += digit;
		strptr++;
	}
	if (endptr)
		*endptr = (char *) strptr;
	return (result * sign);
}
