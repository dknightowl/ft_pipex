/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 09:32:55 by dkhoo             #+#    #+#             */
/*   Updated: 2025/05/08 11:43:20 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description:
	If c is a uppercase letter, tolower() returns its lowercase
	equivalent, if a lowercase representation exists in the current
	locale.
Return value:
	The converted letter, or c if the conversion was not possible
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}
