/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:32:19 by dkhoo             #+#    #+#             */
/*   Updated: 2025/05/08 11:10:19 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description:
	Checks for a digit (0 through 9).
Return Value:
	Nonzero if the character c falls into the tested class,
	and zero if not.
*/

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
