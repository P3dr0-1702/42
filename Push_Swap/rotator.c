/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:46:37 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/01 11:50:08 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

int	rotate_to_min(t_stack *target)
{
	int	min;

	min = *(int *)target->content;
	while (target)
	{
		if (min > *(int *)(target)->content)
			min = *(int *)target->content;
		target = target->next;
	}
	return (min);
}

int	rotate_to_max(t_stack *s)
{
	int		idx;
	int		max_idx;
	int		max_val;
	t_stack	*cur;

	idx = 0;
	max_idx = 0;
	cur = s;
	if (!cur)
		return (0);
	max_val = *(int *)cur->content;
	while (cur)
	{
		if (*(int *)cur->content > max_val)
		{
			max_val = *(int *)cur->content;
			max_idx = idx;
		}
		cur = cur->next;
		idx++;
	}
	return (max_idx);
}

void	rotate_to_extremes(t_stack **a, t_stack **b, t_list *lis)
{
	int	indexa;
	int	indexb;

	indexa = find_index(*a, rotate_to_min(*a));
	indexb = find_index(*b, rotate_to_max(*b));
	rotation_judge_nopush(a, b, indexa, indexb);
	lis = NULL;
}
