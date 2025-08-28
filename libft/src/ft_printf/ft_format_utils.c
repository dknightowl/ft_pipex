/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:33:00 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/28 15:42:57 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
=========================================================
	Various utility functions for t_fmt format struct
=========================================================
*/

/**
	@brief Checks if the character corresponds to a valid
	type specifier that ft_printf handles

	@param c Character to check

	@return Positive value if valid, or 0 if invalid
*/
int	ft_is_valid_type(char c)
{
	return (c == '%'
		|| c == 'c'
		|| c == 's'
		|| c == 'p'
		|| c == 'd'
		|| c == 'i'
		|| c == 'u'
		|| c == 'x'
		|| c == 'X');
}

/**
	@brief Checks if the character corresponds to a valid
	flag that ft_printf handles

	@param c Character to check

	@return Positive value if valid, or 0 if invalid
*/
int	ft_is_valid_flag(char c)
{
	return (c == '-'
		|| c == '+'
		|| c == ' '
		|| c == '0'
		|| c == '#'
	);
}

/**
	@brief Extracts the next format specifier substring from the
	entire FORMAT string starting from the starting index providing.
	Reading starts after '%' so the returned string will not include
	it.

	Note: This does NOT check the format specifier string for its validity
	but merely attempts to extract what is likely to represent a format
	specifier.

	Parsing stops upon encountering one of the following:
		- % (start of another specifier)
		- \ (escape or invalid)
		- (space)
		- Valid format type (should be at the end of any format specifier)

	@param format Complete FORMAT string passed to ft_printf
	@param start_idx Index to start reading the string from.

	@return Newly allocated string containing the format
	representing the next format specifier (e.g. "%-05.2s"), or
	NULL if an error occurred or the substring has an invalid syntax.
*/
char	*ft_next_fmt_str(const char *format, unsigned int start_idx)
{
	unsigned int	end_idx;

	end_idx = start_idx;
	while (ft_is_valid_flag(format[end_idx]))
		end_idx++;
	while (format[end_idx] != '%'
		&& format[end_idx] != '\\'
		&& format[end_idx] != ' '
		&& !ft_is_valid_type(format[end_idx])
	)
		end_idx++;
	return (ft_substr(format, start_idx, end_idx - start_idx + 1));
}

/**
	@brief Initializes and returns a specifier struct with default
	values

	@param None.

	@return The newly-created struct initialized with default
	values.
*/
t_fmt	*ft_new_format(void)
{
	t_fmt	*new_specifier;

	new_specifier = (t_fmt *) malloc (sizeof(t_fmt));
	if (!new_specifier)
		return (NULL);
	ft_memset(new_specifier->flags, 0, PRINTF_FLAGS_LIMIT);
	new_specifier->width = 0;
	new_specifier->precision = -1;
	new_specifier->type = '\0';
	return (new_specifier);
}
