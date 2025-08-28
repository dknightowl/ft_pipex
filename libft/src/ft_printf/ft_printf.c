/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:49:55 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/28 15:42:57 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_print_by_format(t_fmt *fmt, va_list args)
{
	int	result;

	result = ERROR;
	if (fmt->type == '%')
		result = ft_print_char('%');
	else if (fmt->type == 'c')
		result = ft_printf_c(fmt, (const char) va_arg(args, int));
	else if (fmt->type == 's')
		result = ft_printf_s(fmt, va_arg(args, char *));
	else if (fmt->type == 'p')
		result = ft_printf_p(fmt, va_arg(args, void *));
	else if (fmt->type == 'd' || fmt->type == 'i')
		result = ft_printf_i(fmt, va_arg(args, int), SIGNED);
	else if (fmt->type == 'u')
		result = ft_printf_i(fmt, va_arg(args, unsigned int), UNSIGNED);
	else if (fmt->type == 'x')
		result = ft_printf_x(fmt, va_arg(args, unsigned int), LOWERCASE);
	else if (fmt->type == 'X')
		result = ft_printf_x(fmt, va_arg(args, unsigned int), UPPERCASE);
	return (result);
}

static int	ft_parse_and_print_format(
	const char *format,
	size_t *curr_idx,
	va_list args
)
{
	char	*fmt_s;
	t_fmt	*fmt;
	int		result;

	*curr_idx += 1;
	fmt_s = ft_next_fmt_str(format, *curr_idx);
	if (!fmt_s)
		return (ERROR);
	fmt = ft_new_format();
	if (!fmt)
		return (free(fmt_s), ERROR);
	ft_set_format(fmt_s, fmt);
	*curr_idx += ft_strlen(fmt_s);
	if (fmt->type != '\0')
		result = ft_print_by_format(fmt, args);
	else
		result = ft_printf_rawf(fmt_s);
	ft_free_all(fmt_s, fmt, NULL);
	return (result);
}

/**
	@brief Print ARGUMENT(s) according to FORMAT to stdout.

		Implements the following conversions:
			• %c Prints a single character.
			• %s Prints a string (as defined by the common C convention).
			• %p The void * pointer argument has to be printed in hexadecimal
			format.
			• %d Prints a decimal (base 10) number.
			• %i Prints an integer in base 10.
			• %u Prints an unsigned decimal (base 10) number.
			• %x Prints a number in hexadecimal (base 16) lowercase format.
			• %X Prints a number in hexadecimal (base 16) uppercase format.
			• %% Prints a percent sign.

	@param format Contains format specifiers and characters to be printed
	@param ... Lists arguments to be printed in the order of the format
	specifiers listed in the FORMAT string

	@return Upon success, returns the number of characters printed
	(excluding the null byte used to end output to strings).
	If an output error is encountered, a negative value (ERROR) is
	returned.
*/
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		done;
	int		o_done;
	size_t	idx;

	done = 0;
	o_done = done;
	va_start(args, format);
	idx = 0;
	while (format[idx])
	{
		o_done = done;
		if (format[idx] == '%')
			done += ft_parse_and_print_format(format, &idx, args);
		else
		{
			done += ft_print_char(format[idx]);
			idx += 1;
		}
		if (done < o_done)
			return (va_end(args), ERROR);
	}
	va_end(args);
	return (done);
}
