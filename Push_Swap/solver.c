/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:14:48 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/20 11:10:13 by pfreire-         ###   ########.fr       */
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
		if (curr < next && (value >= next || value <= curr))
			return (index + 1);
		index++;
		temp = temp->next;
	}
	return (0);
}

void	rotation_judge(t_stack **b, int index)
{
	int	size;

	size = ft_stacksize(*b);
	if (index <= size / 2)
	{
		while (index > 0)
		{
			r_op(b, 'b');
			index--;
		}
	}
	else
	{
		index = ft_stacksize(*b) - index;
		while (index > 0)
		{
			rr_op(b, 'b');
			index--;
		}
	}
}

void	bouncer(t_stack **a, t_stack **b, t_list *LIS)
{
	int	i;
	int	*val;
	int	index;
	int	size;

	i = -1;
	size = ft_stacksize(*a);
	val = (int *)(*a)->content;
	if (is_in_the_LIS_list(LIS, val))
		r_op(a, 'a');
	else
	{
		if (ft_stacksize(*b) < 2)
			p_op(a, b, 'b');
		else
		{
			index = find_index(*b, *val);
			rotation_judge(b, index);
			p_op(a, b, 'b');
		}
	}
	r_op(b, 'b');
}

int	is_in_the_LIS_list(t_list *LIS, int *val)
{
	while (LIS)
	{
		if (*(int *)LIS->content == *val)
			return (1);
		LIS = LIS->next;
	}
	return (0);
}
