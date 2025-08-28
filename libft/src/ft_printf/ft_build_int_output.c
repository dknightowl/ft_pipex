/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_int_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 23:04:49 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/28 15:42:58 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_apply_sign(t_fmt *fmt, int arg, t_sign_state sign)
{
	char	*output_s;
	char	*tmp;

	tmp = NULL;
	if (sign == UNSIGNED)
		output_s = ft_itoa((unsigned int) arg);
	else
	{
		output_s = ft_itoa(arg);
		if (arg >= 0)
		{
			if (ft_idxof_c('+', fmt->flags) != IDX_NOT_FOUND)
			{
				tmp = output_s;
				output_s = ft_strjoin("+", output_s);
			}
			else if (ft_idxof_c(' ', fmt->flags) != IDX_NOT_FOUND)
			{
				tmp = output_s;
				output_s = ft_strjoin(" ", output_s);
			}
			free(tmp);
		}
	}
	return (output_s);
}

static char	*ft_build_negative_padded(char *s, int s_len, char *padding)
{
	char	*numeric_s;
	char	*tmp;
	char	*output_s;

	numeric_s = ft_substr(s, 1, s_len);
	if (!numeric_s)
		return (NULL);
	tmp = ft_strjoin(padding, numeric_s);
	if (!tmp)
		return (free(numeric_s), NULL);
	output_s = ft_strjoin("-", tmp);
	ft_free_all(numeric_s, tmp, NULL);
	if (!output_s)
		return (NULL);
	return (output_s);
}

/**
	@brief Formats an integer string value for precision

	If precision exceeds the length of the integer string,
	it will be left-padded with zeroes If is it less than,
	the integer string will not be truncated. Signs are
	not accounted for in precision.

	@param precision Integer value representing the precision
	@param s Integer string to be formatted

	@return The string formatted for precision (if applicable),
	or NULL if an error occurred.
*/
static char	*ft_apply_precision(int precision, char *s)
{
	int		is_negative;
	char	*output_s;
	int		s_len;
	char	*padding;

	is_negative = s[0] == '-';
	s_len = (int) ft_strlen(s) - is_negative;
	if (precision > s_len)
	{
		padding = ft_new_padding('0', precision - s_len);
		if (!padding)
			return (NULL);
		if (is_negative)
			output_s = ft_build_negative_padded(s, s_len, padding);
		else
			output_s = ft_strjoin(padding, s);
		free(padding);
		return (output_s);
	}
	return (ft_strdup(s));
}

/**
	@brief Formats an integer string value for width

	If width exceeds the length of the numeric string, it
	will be left-padded with spaces by default. If it is less
	than, no truncation will be done.

	@param fmt Format struct containing width and flags
	information
	@param s String to be formatted

	@return The numeric string formatted for width (if applicable),
	or NULL if an error occurred.
*/
static char	*ft_apply_width(t_fmt *fmt, char *s, int is_negative)
{
	char	*output_s;
	int		s_len;
	char	*padding;

	s_len = (int) ft_strlen(s);
	if (fmt->width > s_len)
	{
		if (ft_idxof_c('0', fmt->flags) == IDX_NOT_FOUND)
			padding = ft_new_padding(' ', fmt->width - s_len);
		else
			padding = ft_new_padding('0', fmt->width - s_len);
		if (!padding)
			return (NULL);
		if (ft_idxof_c('-', fmt->flags) == IDX_NOT_FOUND)
		{
			if (is_negative && ft_idxof_c('0', fmt->flags) != IDX_NOT_FOUND)
				output_s = ft_build_negative_padded(s, s_len, padding);
			else
				output_s = ft_strjoin(padding, s);
		}
		else
			output_s = ft_strjoin(s, padding);
		return (free(padding), output_s);
	}
	return (ft_strdup(s));
}

/**
	@brief Formats and prints the final output for a signed or
	unsigned integer according to the given format. If is_unsigned
	is true while the provided arg is signed, arg will be
	converted to an unsigned value.

	@param fmt Format struct containing details for formatting
	@param arg Signed or unsigned integer to be formatted in the output
	@param sign SIGNED or UNSIGNED flag to determine whether to handle
	arg as a signed or unsigned integer.

	@return The final string to be printed to stdout, or NULL
	if an error occurred.
*/
char	*ft_build_int_output(t_fmt *fmt, int arg, t_sign_state sign)
{
	char	*output_s;
	char	*tmp;

	output_s = ft_apply_sign(fmt, arg, sign);
	if (!output_s)
		return (NULL);
	tmp = output_s;
	output_s = ft_apply_precision(fmt->precision, output_s);
	free(tmp);
	if (!output_s)
		return (NULL);
	tmp = output_s;
	output_s = ft_apply_width(fmt, output_s, (arg < 0 && sign == SIGNED));
	free(tmp);
	if (!output_s)
		return (NULL);
	return (output_s);
}
