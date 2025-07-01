/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lazy_mover.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:36:22 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/01 11:45:26 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

int	get_node_index(t_stack *a, t_stack *target)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a == target)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

void	move_cheapest(t_stack **a, t_stack **b, t_list *lis)
{
	t_stack	*target;
	int		indexb;

	update_cost(*a, *b, lis);
	target = cheapest_node(*a);
	if (!target)
		return ;
	indexb = find_index(*b, *(int *)target->content);
	rotation_judge(a, b, get_node_index(*a, target), indexb);
}

int	notmembers_of_lis(t_stack *a, t_list *lis)
{
	int	count;

	count = 0;
	while (a)
	{
		if (!is_in_the_lis_list(lis, (int *)a->content))
			count++;
		a = a->next;
	}
	return (count);
}
