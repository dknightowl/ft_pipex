/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:04:59 by dkhoo             #+#    #+#             */
/*   Updated: 2025/05/23 12:58:09 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
	@brief Parses flags from format string into the format struct,
	and returns the length of the flags string to allow reading of
	the format string from the index after the flags string.

	@param s Format specifier string to parse the flags from
	@param fmt Format struct to read flags into
	@param start_idx Index to start reading the flags from

	@return Length of flags string
*/
static int	ft_parse_flags(char *s, t_fmt *fmt, int start_idx)
{
	int	flags_idx;
	int	s_idx;

	flags_idx = 0;
	s_idx = start_idx;
	while (ft_is_valid_flag(s[s_idx]) && flags_idx < PRINTF_FLAGS_LIMIT)
	{
		if (ft_idxof_c(s[s_idx], fmt->flags) == IDX_NOT_FOUND)
		{
			fmt->flags[flags_idx] = s[s_idx];
			flags_idx++;
		}
		s_idx++;
	}
	return (s_idx - start_idx);
}

/**
	@brief Parses a number value from format string into the format struct,
	then returns the length of the number string to allow reading of
	the format string from the index after the number value.

	@param s Format specifier string to parse the number value from
	@param fmt Format struct to read the number value into
	@param start_idx Index to start reading the FORMAT string from
	@param type The format number type to determine which field to read the
	number value into (WIDTH or PRECISION)

	@return Length of number value. E.g. a number of "123" returns 3.
*/
static int	ft_parse_num(char *s, t_fmt *fmt, int start_idx, t_fmtnumtype type)
{
	int		idx;
	int		len;
	char	*num_s;
	int		num;

	idx = start_idx;
	while (ft_isdigit(s[idx]))
		idx++;
	len = idx - start_idx;
	if (len > 0)
	{
		num_s = ft_substr(s, start_idx, len);
		if (!num_s)
			return (0);
		num = ft_atoi(num_s);
		free(num_s);
		if (type == WIDTH)
			fmt->width = num;
		else if (type == PRECISION)
			fmt->precision = num;
		return (len);
	}
	return (0);
}

/**
	@brief Parses the format type value from format specifier string
	into the format struct. No value is returned as it is assumed that
	type is at the end of the specifier string.

	@param s The format specifier string to parse the type from
	@param fmt The format struct to read the type value into
	@param start_idx The index to start reading the format specifier
	string from

	@return None.
*/
static void	ft_parse_type(char *s, t_fmt *fmt, int idx)
{
	if (ft_is_valid_type(s[idx]))
		fmt->type = s[idx];
	else
		fmt->type = '\0';
}

/**
	@brief Parses the format string into the given format struct

	Syntax of specifier string:
		[flags][width][.precision][type]
		where:
			- flags (optional): Represents a unique array of up
			to 5 unique flag characters (-, +, (space), 0, #)
			- width (optional): Represents an integer value
			- precision (optional): Represents an integer value
			- type (mandatory): Represents a character value

	If the format string has an invalid syntax, the format type
	cannot be determined (ft_parse_type) and will be set to '\0'.

	@param fmt_s The format string to parse values from
	@param fmt The format struct to parse values into

	@return None
*/
void	ft_set_format(char *fmt_s, t_fmt *fmt)
{
	int	idx;

	idx = 0;
	idx += ft_parse_flags(fmt_s, fmt, idx);
	idx += ft_parse_num(fmt_s, fmt, idx, WIDTH);
	if (fmt_s[idx] == '.')
	{
		idx += 1;
		if (ft_isdigit(fmt_s[idx]))
			idx += ft_parse_num(fmt_s, fmt, idx, PRECISION);
		else
			fmt->precision = 0;
	}
	ft_parse_type(fmt_s, fmt, idx);
}
