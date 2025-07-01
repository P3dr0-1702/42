/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lazy_unmover.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:46:37 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/27 14:12:49 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

void	rotation_judge_b2a(t_stack **a, t_stack **b, int indexa, int indexb)
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
	//p_op(b, a, 'a');
}

// static int	find_pos_index(t_stack *a, int value)
// {
// 	int		index;
// 	t_stack	*curr;

// 	index = 0;
// 	curr = a;
// 	while (curr->next)
// 	{
// 		if (*(int *)curr->content > value
//			&& *(int *)curr->next->content < value)
// 			return (index + 1);
// 		curr = curr->next;
// 		index++;
// 	}
// 	return (0);
// }

// static void	reset_cost(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		stack->cost = 0;
// 		stack = stack->next;
// 	}
// }

// void	move_cheapest_b2a(t_stack **a, t_stack **b, t_list *lis)
// {
// 	t_stack	*target;
// 	int		indexa;
// 	int		indexb;

// 	rotate_to_the_top(*a, *b);
// }

int	rotate_to_min(t_stack *target)
{
	int min;

	min = *(int *)target->content;
	while (target)
	{
		if (min > *(int *)(target)->content)
			min = *(int*)target->content;
		target = target->next;
	}
	return (min);
}
int rotate_to_max(t_stack *s)
{
    int     idx = 0;
    int     max_idx = 0;
    int     max_val;
    t_stack *cur = s;

    if (!cur)
        return 0;
    max_val = *(int*)cur->content;
    while (cur)
    {
        if (*(int*)cur->content > max_val)
        {
            max_val = *(int*)cur->content;
            max_idx = idx;
        }
        cur = cur->next;
        idx++;
    }
    return max_idx;
}

// int rotate_to_max(t_stack *target)
// {
// 	int	max;

// 	max = *(int*)target;
// 	while (target)
// 	{
// 		if (max < *(int *)(target)->content)
// 			max = *(int*)target->content;
// 		target = target->next;
// 	}
// 	return (max);
// }

void	move_cheapest_b2a(t_stack **a, t_stack **b, t_list *lis)
{
	int indexa;
	int indexb;

	indexa = find_index(*a, rotate_to_min(*a));
	indexb = find_index(*b, rotate_to_max(*b));
	rotation_judge_b2a(a, b, indexa, indexb);
	lis = NULL;
}