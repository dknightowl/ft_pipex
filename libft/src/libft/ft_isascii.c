/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:19:12 by dkhoo             #+#    #+#             */
/*   Updated: 2025/05/08 11:10:07 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description:
	Checks whether c is a 7-bit unsigned char value that
	fits into the ASCII character set
Return value:
	Nonzero if the character c falls into the tested class,
	and zero if not
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
