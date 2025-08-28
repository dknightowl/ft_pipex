/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_rawf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:26:20 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/28 15:42:57 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
	@brief Prints the raw format string as-is - likely due to the
	format string having an invalid syntax and thus being unable
	to be processed.

	@param fmt_s Raw format string (excluding '%') to be printed

	@return Number of bytes printed, or ERROR (-1) if an error
	occurred
*/
int	ft_printf_rawf(char *fmt_s)
{
	char	*percent_s;
	char	*output_s;
	int		byte_count;

	percent_s = ft_ctoa('%');
	if (!percent_s)
		return (ERROR);
	output_s = ft_strjoin(percent_s, fmt_s);
	if (!output_s)
		return (free(percent_s), ERROR);
	byte_count = ft_print_str(output_s);
	free(output_s);
	return (byte_count);
}
