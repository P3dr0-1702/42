/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:14:48 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/16 17:02:05 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

int	find_index(t_stack *b, int value)
{
	int		index;
	int		max;
	int		min;
	t_stack	*temp;

	index = 0;
	temp = b;
	while (temp)
	{
		if (min < *(int *)temp->content && *(int *)temp->content < value)
			min = *(int *)temp->content;
		if (max > *(int *)temp->content && *(int *)temp->content > value)
			max = *(int *)temp->content;
		temp = temp->next;
	}
	while (b)
	{
		if (*(int *)b->content == min && *(int *)b->next->content == max)
			return (index);
		b = b->next;
		index++;
	}
	return (INT_MIN);
}

void	rotation_judge(t_stack **b, int index)
{
	if (index <= ft_stacksize(*b) / 2)
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

	i = 0;
	size = ft_stacksize(*a);
	while (i < size)
	{
		val = (int *)(*a)->content;
		if (is_in_the_LIS_list(LIS, val)) r_op(a, 0);
		else
		{
			if (ft_stacksize(*b) <= 2)
				p_op(a, b, 0);
			else
			{
				index = find_index(*b, *val);
				rotation_judge(b, index);
				p_op(a, b, 0);
			}
		}
		i++;
	}
	r_op(b, 0);
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
