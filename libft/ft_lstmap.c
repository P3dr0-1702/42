/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:55:10 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/14 11:10:13 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n;
	t_list	*new_lst;

	new_lst = NULL;
	while (lst)
	{
		n = malloc(sizeof(t_list));
		if (!n)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		n->content = (*f)(lst->content);
		n->next = NULL;
		ft_lstadd_back(&new_lst, n);
		lst = lst->next;
	}
	return (new_lst);
}
