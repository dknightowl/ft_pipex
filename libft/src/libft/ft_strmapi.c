/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:13:03 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/27 00:15:16 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
Description:
	Applies the function f to each character of the
	string s, passing its index as the first argument
	and the character itself as the second. A new
	string is created (using malloc(3)) to store the
	results from the successive applications of f.
Return value:
	The string created from the successive applications
	of ’f’, or NULL if the allocation fails.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*f_str;
	unsigned int	len;
	unsigned int	i;

	len = (unsigned int) ft_strlen(s);
	f_str = (char *) malloc(len + 1);
	if (!f_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		f_str[i] = f(i, s[i]);
		i++;
	}
	f_str[i] = '\0';
	return (f_str);
}
