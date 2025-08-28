/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:47:42 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/27 10:11:43 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	@brief Returns whether or not c is an uppercase letter

	@param c The character to check

	@return Nonzero if the character c falls into the tested
	class, and zero if not
*/
int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
