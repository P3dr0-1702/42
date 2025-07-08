/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_reverse_iter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:13:37 by pfreire-          #+#    #+#             */
/*   Updated: 2025/05/15 16:28:09 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief reverse iterates through stack and aplies function f to every node
/// @param lst list
/// @param f function to aplly
void	ft_stack_reverse_iter(t_stack *lst, void (*f)(void *))
{
	t_stack	*i;

	if (!lst)
		return ;
	i = lst;
	while (i != NULL)
	{
		(*f)(i->content);
		i = i->prev;
	}
}
