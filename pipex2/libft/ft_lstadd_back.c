/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:33:26 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/17 12:34:26 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Add a node at the end of a list
/// @param lst list 
/// @param  new node to add in the end
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*i;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	i = *lst;
	while (i->next != NULL)
		i = i->next;
	i->next = new;
}
