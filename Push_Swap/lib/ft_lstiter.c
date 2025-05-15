/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:52:41 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/21 15:30:48 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Iterates through list and aplies function f to every node
/// @param lst list
/// @param f function to aplly
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*i;

	if (!lst)
		return ;
	i = lst;
	while (i != NULL)
	{
		(*f)(i->content);
		i = i->next;
	}
}
