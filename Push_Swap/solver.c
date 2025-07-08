/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:14:48 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/08 18:53:48 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

int	find_index(t_stack *b, int value)
{
	t_stack	*temp;
	int		index;
	int		curr;
	int		next;

	if (!b || !b->next)
		return (0);
	index = 0;
	temp = b;
	while (temp->next)
	{
		curr = *(int *)temp->content;
		next = *(int *)temp->next->content;
		if (curr >= value && value >= next)
			return (index + 1);
		else if (curr < next && (value >= next || value <= curr))
			return (index + 1);
		index++;
		temp = temp->next;
	}
	return (0);
}

int	is_in_the_lis_list(t_list *lis, int *val)
{
	if (!lis)
		return (0);
	while (lis)
	{
		if (*(int *)lis->content == *val)
			return (1);
		lis = lis->next;
	}
	return (0);
}

void	all_to_a(t_stack **a, t_stack **b)
{
	int	i;
	int	bval;

	i = last_val(*a);
	bval = *(int *)(*b)->content;
	if (bval == *(int *)(*a)->content - 1)
		p_op(b, a, 'a');
	else
		rr_op(a, 'a');
}

void	solver(t_stack *a, t_stack *b, t_list *lis)
{
	if (!a || !a->next || is_stack_solved(a, 0))
		return ;
	if (ft_stacksize(a) <= 3)
		quick_solve(a);
	else
	{
		while (notmembers_of_lis(a, lis) > 0)
			move_cheapest(&a, &b, lis);
		while (!(is_stack_solved(a, 0)))
			rotate_to_extremes(&a, &b, lis);
		if (!b)
			return ;
		while (!(is_stack_solved(b, 1)))
			r_op(&b, 'b');
		if (last_val(a) < *(int *)b->content)
			p_op(&b, &a, 'a');
		while (b)
			all_to_a(&a, &b);
		while (!(is_stack_solved(a, 0)))
			rr_op(&a, 'a');
	}
}
