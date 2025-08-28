/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:16:30 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/27 00:15:16 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
Description:
	Deletes and frees the given node and all its
	successors, using the function ’del’ and free(3).
	Finally, set the pointer to the list to NULL.
Return value:
	None.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_ptr;

	if (!lst || !del)
		return ;
	lst_ptr = *lst;
	while (lst_ptr)
	{
		lst_ptr = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = lst_ptr;
	}
}
