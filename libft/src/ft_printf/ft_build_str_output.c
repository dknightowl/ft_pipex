/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_str_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:44:42 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/28 15:42:57 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
	@brief Allocates and returns a copy of the string "(null)"

	@return Pointer to the null-terminated string containing
	"(null)", or NULL if an error occurred
*/
static char	*ft_null_buffer(void)
{
	char		*buffer;
	const char	*null_str;
	char		len;

	null_str = "(null)";
	len = ft_strlen(null_str);
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, null_str, len + 1);
	return (buffer);
}

/**
	@brief Formats a string value for precision

	If precision is less than the length of the string,
	it will be truncated. If it exceeds, no padding will
	be done by default.

	@param precision Integer value representing the precision
	@param s String to be formatted

	@return The string formatted for precision (if applicable),
	or NULL if an error occurred
*/
static char	*ft_apply_precision(int precision, char *s)
{
	char	*output_s;

	if (precision < (int) ft_strlen(s))
		output_s = ft_substr((const char *) s, 0, precision);
	else
		output_s = ft_strdup((const char *) s);
	return (output_s);
}

/**
	@brief Formats a string value for width

	If width exceeds the length of the result string, it
	default to padding with spaces from the start. If it is
	less than, the string will not be truncated by default

	@param fmt Format struct containing width and flags
	information
	@param s String to be formatted

	@return The string formatted for width (if applicable),
	or NULL if an error occurred
*/
static char	*ft_apply_width(t_fmt *fmt, char *s)
{
	char	*output_s;
	int		s_len;
	char	*padding;

	if (!fmt || !s)
		return (NULL);
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
			output_s = ft_strjoin(padding, s);
		else
			output_s = ft_strjoin(s, padding);
		free(padding);
		if (!output_s)
			return (NULL);
		return (output_s);
	}
	return (ft_strdup(s));
}

/**
	@brief Formats and returns the final output string
	for a given string and format struct. If the string
	pointer is NULL, "(null)" will be printed by default.

	@param fmt The format struct to retrieve formatting
	information from
	@param arg The string argument to be formatted. This
	needs to be null-terminated.

	@return The final string to be printed to stdout, or NULL
	if an error occurred.
*/
char	*ft_build_str_output(t_fmt *fmt, char *arg)
{
	char	*output_s;
	char	*tmp;

	output_s = NULL;
	tmp = NULL;
	if (!arg && fmt->type != 'c')
		return (ft_null_buffer());
	output_s = ft_apply_precision(fmt->precision, arg);
	if (!output_s)
		return (NULL);
	tmp = output_s;
	output_s = ft_apply_width(fmt, output_s);
	free(tmp);
	if (!output_s)
		return (NULL);
	return (output_s);
}
