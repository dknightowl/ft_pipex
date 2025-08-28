/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:44:42 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/11 11:48:02 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	@brief Returns whether or not c is a lowercase letter

	@param c The character to check

	@return Nonzero if the character c falls into the tested
	class, and zero if not
*/

int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
