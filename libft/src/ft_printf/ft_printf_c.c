/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:54:06 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/28 15:42:57 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
	@brief Returns the padding string for '\0' characters

	@param fmt Format struct containing formatting information

	@return Padding string, or NULL if an error occurred
*/
static char	*ft_null_padding(t_fmt *fmt)
{
	char	*padding;
	int		padding_len;

	padding_len = fmt->width;
	if (ft_idxof_c('0', fmt->flags) == IDX_NOT_FOUND)
		padding = ft_new_padding(' ', padding_len);
	else
		padding = ft_new_padding('0', padding_len);
	if (!padding)
		return (NULL);
	return (padding);
}

static int	ft_print_null(t_fmt *fmt)
{
	char	*output_s;
	int		byte_count;

	byte_count = 0;
	if (ft_idxof_c('-', fmt->flags) != IDX_NOT_FOUND)
		byte_count += ft_print_char(0);
	if (fmt->width > 0)
	{
		output_s = ft_null_padding(fmt);
		if (!output_s)
			return (ERROR);
		byte_count = ft_print_str(output_s);
		free(output_s);
	}
	if (ft_idxof_c('-', fmt->flags) == IDX_NOT_FOUND)
		byte_count += ft_print_char(0);
	return (byte_count);
}

int	ft_printf_c(t_fmt *fmt, char arg)
{
	char	*char_s;
	char	*output_s;
	int		byte_count;

	byte_count = 0;
	if (arg)
	{
		char_s = ft_ctoa(arg);
		if (!char_s)
			return (ERROR);
		output_s = ft_build_str_output(fmt, char_s);
		free(char_s);
		if (!output_s)
			return (ERROR);
		byte_count = ft_print_str(output_s);
		free(output_s);
	}
	else
		byte_count = ft_print_null(fmt);
	return (byte_count);
}
