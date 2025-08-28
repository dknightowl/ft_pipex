/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 09:31:09 by dkhoo             #+#    #+#             */
/*   Updated: 2025/05/16 11:29:20 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description:
	Checks for any printable character including space
Return Value:
	Nonzero if the character c falls into the tested class,
	and zero if not
*/

int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}
