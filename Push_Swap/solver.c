/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:14:48 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/25 15:44:45 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

int	abs(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

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

void	rr_sop_multi(t_stack **a, t_stack **b, int *indexa, int *indexb)
{
	while (*indexa < 0 && *indexb < 0)
	{
		rrr_sop(a, b, "rr");
		(*indexa)++;
		(*indexb)++;
	}
	while (*indexa < 0)
	{
		rr_op(a, 'a');
		(*indexa)++;
	}
	while (*indexb < 0)
	{
		rr_op(b, 'b');
		(*indexb)++;
	}
}

void	r_sop_multi(t_stack **a, t_stack **b, int *indexa, int *indexb)
{
	while (*indexa > 0 && *indexb > 0)
	{
		rr_sop(a, b, "r");
		(*indexa)--;
		(*indexb)--;
	}
	while (*indexa > 0)
	{
		r_op(a, 'a');
		(*indexa)--;
	}
	while (*indexb > 0)
	{
		r_op(b, 'b');
		(*indexb)--;
	}
}

void rotation_judge_a2b(t_stack **a, t_stack **b, int indexa, int indexb)
{
	int	siza;
	int	sizb;
	int	offseta;
	int	offsetb;

	siza = ft_stacksize(*a);
	sizb = ft_stacksize(*b);
	offseta = indexa;
	if ((indexa > siza / 2))
		offseta = (abs(indexa - siza)) * -1;
	offsetb = indexb;
	if ((indexb > sizb / 2))
		offsetb = (abs(indexb - sizb)) * -1;
	rr_sop_multi(a, b, &offseta, &offsetb);
	r_sop_multi(a, b, &offseta, &offsetb);
	p_op(a, b, 'b');
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
