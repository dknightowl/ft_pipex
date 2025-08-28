/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:50:14 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/28 15:42:57 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
============================================
	Helper print functions for ft_printf
============================================
*/

/**
	@brief Prints a single character

	@param c Character to be printed

	@return Number of bytes printed
*/
int	ft_print_char(const char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

/**
	@brief Prints a string (as defined by the common C convention)

	@param s The string to be printed. This must be null-terminated.

	@return Number of bytes printed
*/
int	ft_print_str(const char *s)
{
	int	byte_count;

	byte_count = 0;
	while (s[byte_count])
		byte_count += ft_print_char(s[byte_count]);
	return (byte_count);
}
