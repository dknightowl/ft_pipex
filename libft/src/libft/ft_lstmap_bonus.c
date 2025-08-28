/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:32:15 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/27 00:15:16 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
Description:
	Iterates through the list ’lst’, applies the
	function ’f’ to each node’s content, and creates
	a new list resulting of the successive applications
	of the function ’f’. The ’del’ function is used to
	delete the content of a node if needed.
Return value:
	The new list, or NULL if allocation fails
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	new_node = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			ft_lstclear(&new_lst, (*del));
			free(new_content);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
// #include <stdio.h>
// int main(void)
// {
// 	int tab[] = {0, 1, 2, 3};
// 	t_list *l =  ft_lstnew(tab);
// 	t_list * tmp = l;
// 	for (int i = 1; i < 4; ++i)
// 		ft_lstadd_back(&l, ft_lstnew(tab + i));
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		printf("%d)content: %d\n", i, *((int*)tmp->content));
// 		tmp = (t_list *)tmp->next;
// 	}
// 	return (0);
// }