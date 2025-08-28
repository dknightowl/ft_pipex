/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:16:38 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/28 15:42:57 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
	@brief Formats and prints integer strings

	@param fmt Format struct containing formatting information
	@param arg Integer to be formatted and printed
	@param sign States whether the integer is to be treated as
	signed or unsigned

	@return Number of bytes printed, or ERROR (-1) if an error
	occurred
*/

int	ft_printf_i(t_fmt *fmt, int arg, t_sign_state sign)
{
	char	*output_s;
	int		byte_count;

	output_s = ft_build_int_output(fmt, arg, sign);
	if (!output_s)
		return (ERROR);
	byte_count = ft_print_str(output_s);
	free(output_s);
	return (byte_count);
}
