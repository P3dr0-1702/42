/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_PS_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:03:42 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/24 15:13:40 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

t_stack	*non_ps_solver(t_stack **a)
{
	int		value;
	t_stack	*sorted;
	t_stack	*a2;
	t_stack	*new_node;

	sorted = NULL;
	a2 = *a;
	while (a2)
	{
		value = *(int *)a2->content;
		new_node = ft_stack_newnode(value);
		sorted = put_into_stack(sorted, new_node);
		a2 = a2->next;
	}
	return (sorted);
}

t_stack	*put_into_stack(t_stack *sorted, t_stack *node)
{
	int		sorting;
	t_stack	*stop;

	sorting = *(int *)node->content;
	if (!sorted || sorting < *(int *)sorted->content)
	{
		node->next = sorted;
		if (sorted)
			sorted->prev = node;
		node->prev = NULL;
		return (node);
	}
	stop = sorted;
	while (stop->next && *(int *)stop->next->content < sorting)
		stop = stop->next;
	node->next = stop->next;
	if (stop->next)
		stop->next->prev = node;
	stop->next = node;
	node->prev = stop;
	return (sorted);
}

t_stack	*ft_stack_newnode(int currNBR)
{
	t_stack	*s;
	int		*ptr;

	s = malloc(sizeof(t_stack));
	ptr = malloc(sizeof(int));
	if (!s || !ptr)
		return (NULL);
	*ptr = currNBR;
	s->content = ptr;
	s->next = NULL;
	s->prev = NULL;
	return (s);
}
