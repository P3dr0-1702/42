/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:02:25 by pfreire-          #+#    #+#             */
/*   Updated: 2025/05/15 16:03:53 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Add a node at the end of a stack
/// @param lst list 
/// @param  new node to add in the end
void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*i;

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
	new->prev = i;
}
