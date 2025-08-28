/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:51:23 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/28 15:42:57 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
	@brief Formats and prints integer strings

	@param fmt Format struct containing formatting information
	@param arg String to be formatted and printed

	@return Number of bytes printed, or ERROR (-1) if an error
	occurred
*/
int	ft_printf_s(t_fmt *fmt, char *arg)
{
	char	*output_s;
	int		byte_count;

	output_s = ft_build_str_output(fmt, arg);
	if (!output_s)
		return (ERROR);
	byte_count = ft_print_str(output_s);
	free(output_s);
	return (byte_count);
}
