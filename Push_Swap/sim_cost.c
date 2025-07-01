/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:32:30 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/01 13:47:17 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

int	sim_rotation_judge(t_stack *b, int index)
{
	int	size;

	size = ft_stacksize(b);
	if (index <= size / 2)
		return (index);
	else
		return (size - index);
}

void	update_cost(t_stack *a, t_stack *b, t_list *lis)
{
	t_stack	*curr;
	int		indexa;
	int		indexb;
	int		costa;
	int		costb;

	curr = a;
	indexa = 0;
	while (curr)
	{
		if (is_in_the_lis_list(lis, (int *)curr->content))
			curr->cost = INT_MAX - 1;
		else
		{
			costa = sim_rotation_judge(a, indexa);
			indexb = find_index(b, *(int *)curr->content);
			costb = sim_rotation_judge(b, indexb);
			curr->cost = costa + costb + 1;
		}
		curr = curr->next;
		indexa++;
	}
}

t_stack	*cheapest_node(t_stack *a)
{
	t_stack	*min_node;

	min_node = NULL;
	while (a)
	{
		if (a->cost != INT_MAX && (!min_node || a->cost < min_node->cost))
			min_node = a;
		a = a->next;
	}
	return (min_node);
}
