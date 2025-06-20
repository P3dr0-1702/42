/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tio_patinhas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:36:22 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/20 11:05:09 by pfreire-         ###   ########.fr       */
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
void	rotate_to_node(t_stack **a, t_stack *target)
{
	int	index;
	int	size;

	index = get_node_index(*a, target);
	size = ft_stacksize(*a);
	if (index <= size / 2)
	{
		while (index-- > 0)
			r_op(a, 'a');
	}
	else
	{
		index = size - index;
		while (index-- > 0)
			rr_op(a, 'a');
	}
}
void	move_cheapest(t_stack **a, t_stack **b, t_list *LIS)
{
	t_stack	*target;
	int		indexb;

	update_cost(*a, *b, LIS);
	target = cheapest_node(*a);
	if (!target)
		return ;
	rotate_to_node(a, target);
	indexb = find_index(*b, *(int *)target->content);
	rotation_judge(b, indexb);
	bouncer(a, b, LIS);
}

int	notmembers_of_LIS(t_stack *a, t_list *LIS)
{
	int count;

	count = 0;
	while (a)
	{
		if (!is_in_the_LIS_list(LIS, (int *)a->content))
			count++;
		a = a->next;
	}
	return (count);
}