/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:10:38 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/28 15:42:57 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
	@brief Formats and prints pointer strings

	@param fmt Format struct containing formatting information
	@param p Integer to be formatted and printed

	@return Number of bytes printed, or ERROR (-1) if an error
	occurred
*/
int	ft_printf_p(t_fmt *fmt, void *p)
{
	char	*output_s;
	int		byte_count;
	char	*p_s;

	if (p)
	{
		p_s = ft_ptoa(p);
		if (!p_s)
			return (ERROR);
		output_s = ft_build_ptr_output(fmt, p_s);
		free(p_s);
	}
	else
		output_s = ft_build_ptr_output(fmt, p);
	if (!output_s)
		return (ERROR);
	byte_count = ft_print_str(output_s);
	free(output_s);
	return (byte_count);
}
