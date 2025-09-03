/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:16:28 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/01 15:49:41 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	@brief Custom implementation of isspace(). Checks for white-space characters.

	In the "C" and "POSIX" locales, these are: space, form-feed ('\f'),
	newline ('\n'), carriage return ('\r'), horizontal tab ('\t'), and
	vertical tab ('\v').

	@param c Character to check

	@return Nonzero if character c is a white-space character, and zero if not.
*/
int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}
