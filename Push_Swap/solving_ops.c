/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:36:59 by pfreire-          #+#    #+#             */
/*   Updated: 2025/05/25 18:10:19 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

int	next_in_line(t_stack *solved, int current)
{
	t_stack	*head;

	head = solved;
	while (solved && solved->next)
	{
		if ((int)solved->content == current)
			return ((int)solved->next->content);
		solved = solved->next;
	}
	return ((int)head->content);
}

int	find_target(int curr, t_stack *solved)
{
	int	target;

	target = 0;
	while (solved)
	{
		if (curr == (int)(solved)->content)
			return (target);
		target++;
	}
	return (NULL);
}

int	index_of_curr(int curr, t_stack *solved)
{
	int	i;

	i = 0;
	while (solved)
	{
		if (curr == (int)solved->content)
			return (i);
		i++;
	}
	return (NULL);
}

int	rotation_judge(int index, int size)
{
	if (index > size / 2)
		return (1);
	return (0);
}
void	rotate(t_stack **a, t_stack **b, t_stack *solved, int index,
		int is_reverse_rotation)
{
	while (index < 0)
	{
		if (is_reverse_rotation)
			rr_op(a, 'a');
		else
			r_op(a, a);
		if ((int)(*a)->content == next_in_line(solved, (int)(*b)->content))
			p_op(b, a, 'b');
		index--;
	}
}
