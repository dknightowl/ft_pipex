/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:20:26 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/28 15:42:57 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
	@brief Formats and prints unsigned integers in hexadecimal form

	@param fmt Format struct containing formatting information
	@param uint_n Unsigned integer to be formatted and printed
	@param c_case UPPERCASE or LOWERCASE to indicate whether upper-
	or lowercase letters will be used in the final output

	@return Number of bytes printed, or ERROR (-1) if an error
	occurred
 */
int	ft_printf_x(t_fmt *fmt, unsigned int uint_n, t_char_case c_case)
{
	char	*output_s;
	char	*hex_s;
	char	*tmp;
	int		byte_count;

	hex_s = ft_utohex(uint_n, c_case);
	if (!hex_s)
		return (ERROR);
	if (ft_idxof_c('#', fmt->flags) != IDX_NOT_FOUND && uint_n != 0)
	{
		tmp = hex_s;
		if (c_case == UPPERCASE)
			hex_s = ft_strjoin("0X", hex_s);
		else
			hex_s = ft_strjoin("0x", hex_s);
		free(tmp);
	}
	output_s = ft_build_ptr_output(fmt, hex_s);
	if (!output_s)
		return (free(hex_s), ERROR);
	byte_count = ft_print_str(output_s);
	ft_free_all(hex_s, output_s, NULL);
	return (byte_count);
}
