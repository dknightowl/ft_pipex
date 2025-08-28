/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:51:33 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/27 00:15:16 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
Description:
	Returns a pointer to a new string which is a duplicate of the string s.
	Memory for the new string is obtained  with malloc(3), and can be
	freed with free(3)
Return value:
	On success, the strdup() function returns a pointer to the duplicated
	string. It returns NULL if insufficient memory was available, with
	errno set to indicate the cause of the error.
*/

char	*ft_strdup(const char *s)
{
	char	*s_cpy;
	int		s_len;
	int		i;

	s_len = (int) ft_strlen(s);
	s_cpy = (char *) malloc(s_len + 1);
	if (!s_cpy)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		s_cpy[i] = s[i];
		i++;
	}
	s_cpy[i] = '\0';
	return (s_cpy);
}
