/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:44:08 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/06 10:53:27 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
Description:
	Converts the initial portion of the string pointed to by
	str_ptr to int
Return value:
	Converted value or 0 on error
*/

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *str_ptr)
{
	int	sign;
	int	inum;

	sign = 1;
	inum = 0;
	while (ft_isspace(*str_ptr))
		str_ptr++;
	if (*str_ptr == '-' || *str_ptr == '+')
	{
		if (*str_ptr == '-')
			sign = -1;
		str_ptr++;
	}
	while (*str_ptr != '\0' && ft_isdigit(*str_ptr))
	{
		inum = (inum * 10) + (*str_ptr - '0');
		str_ptr++;
	}
	return (inum * sign);
}
