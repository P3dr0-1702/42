/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illegal_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:19:49 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/01 17:21:14 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

t_stack	*illegal_solver(t_stack **a)
{
	int		value;
	t_stack	*sorted;
	t_stack	*a2;
	t_stack	*new_node;

	sorted = NULL;
	a2 = *a;
	while (a2)
	{
		value = *(int*)a2->content;
		new_node = ft_stack_newnode(value);
		sorted = put_into_stack(sorted, new_node);
		a2 = a2->next;
	}
	return (sorted);
}

t_stack	*put_into_stack(t_stack *sorted, t_stack *node)
{
	t_stack	*sorting;

	if (!sorted || (int*)node->content < (int*)sorted->content)
	{
		node->next = sorted;
		if (sorted)
		{
			sorted->prev = node;
		}
		return (node);
	}
	sorting = sorted;
	while (sorting->next)
	{
		if ((int*)node->content < (int*)sorting->content)
			sorting = sorting->next;
		node->next = sorting->next;
		if (sorting->next)
			sorting->next->prev = node;
		sorting->next = node;
		node->next = sorting;
	}
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
int	check_stack_status(t_stack *a, int is_reverse)
{
	int drops;

	drops = 0;
	while (a->next)
	{
		if (is_reverse)
		{
			if ((int*)a->content > (int*)a->next->content)
				drops++;
		}
		else
		{
			if ((int*)a->content < (int*)a->next->content)
				drops++;
		}
		a = a->next;
	}
	return (drops <= 1);
}
