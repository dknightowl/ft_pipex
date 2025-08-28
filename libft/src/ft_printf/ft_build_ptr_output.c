/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_ptr_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:02:36 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/28 15:42:57 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
	@brief Allocates and returns a copy of the string "(nil)"

	@return Pointer to the null-terminated string containing
	"(nil)", or NULL if an error occurred
*/
static char	*ft_nil_buffer(void)
{
	char	*buffer;

	buffer = malloc(6);
	if (!buffer)
		return (NULL);
	buffer[0] = '(';
	buffer[1] = 'n';
	buffer[2] = 'i';
	buffer[3] = 'l';
	buffer[4] = ')';
	buffer[5] = '\0';
	return (buffer);
}

static char	*ft_apply_precision(t_fmt *fmt, char *s)
{
	int		s_len;
	char	*output_s;
	int		padding_len;
	char	*padding;

	s_len = (int) ft_strlen(s);
	if (fmt->precision > s_len)
	{
		padding_len = fmt->precision - s_len;
		padding = ft_new_padding('0', padding_len);
		if (!padding)
			return (NULL);
		output_s = ft_strjoin(padding, s);
		free(padding);
		if (!output_s)
			return (NULL);
	}
	else
		output_s = ft_strdup(s);
	return (output_s);
}

static char	*ft_apply_width(t_fmt *fmt, char *s)
{
	int		s_len;
	char	*output_s;
	int		padding_len;
	char	*padding;

	s_len = (int) ft_strlen(s);
	if (fmt->width > s_len)
	{
		padding_len = fmt->width - s_len;
		if (ft_idxof_c('0', fmt->flags) == IDX_NOT_FOUND)
			padding = ft_new_padding(' ', padding_len);
		else
			padding = ft_new_padding('0', padding_len);
		if (!padding)
			return (NULL);
		if (ft_idxof_c('-', fmt->flags) == IDX_NOT_FOUND)
			output_s = ft_strjoin(padding, s);
		else
			output_s = ft_strjoin(s, padding);
		free(padding);
	}
	else
		output_s = ft_strdup(s);
	return (output_s);
}

/**
	@brief Formats and returns the final output string
	for a given address string and format struct.

	Rules:
	1) If precision exceeds the length of the output_s string,
	it is left-padded with zeros by default. If it is less
	than, the string will not be truncated.
	2) If width exceeds the length of the output_s string, it
	default to padding with spaces from the start. If it is
	less than, the address will not be truncated.

	@param fmt The format struct to retrieve formatting
	information from
	@param arg The address string to be formatted. This
	needs to be null-terminated.

	@return The final string to be printed to stdout, or NULL
	if an error occurred.
*/
char	*ft_build_ptr_output(t_fmt *fmt, char *ptr_str)
{
	char	*tmp;
	char	*output_s;

	tmp = NULL;
	output_s = NULL;
	if (!ptr_str)
		return (ft_nil_buffer());
	output_s = ft_apply_precision(fmt, ptr_str);
	if (!output_s)
		return (NULL);
	tmp = output_s;
	output_s = ft_apply_width(fmt, output_s);
	free(tmp);
	if (!output_s)
		return (NULL);
	return (output_s);
}
