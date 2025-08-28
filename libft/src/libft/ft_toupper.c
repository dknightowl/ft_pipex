/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 09:33:00 by dkhoo             #+#    #+#             */
/*   Updated: 2025/05/08 11:44:15 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description:
	If c is a lowercase letter, toupper() returns its uppercase
	equivalent,if a uppercase representation exists in the current
	locale.
Return value:
	The converted letter, or c if the conversion was not possible
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c + ('A' - 'a'));
	return (c);
}
