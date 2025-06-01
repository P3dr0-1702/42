/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:07:19 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/01 17:25:49 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

void	legal_solver(t_stack **a, t_stack **b, t_stack **solved)
{
	t_stack *temp;
	int i;

	rotate_sort(a, solved);
	while (!check_stack_status(*a, 0) && !b)
	{
		if ((int*)(*a)->content != (int*)(*solved)->content)
		{
			p_op(a, b, 'b');
			temp = *solved;
			i = *(int*)(*b)->content;
			while((int*)temp->content != &i)
			{
				if((int*)temp->content + 1 == (int*)(*b)->content)
					p_op(a, b, 'a');
				temp = temp->next;
			}
			while(b)
				p_op(b,a,'a');
		}
		rr_sop(a, solved, 'a');
	}
}

void	rotate_sort(t_stack **a, t_stack **solved)
{
	while ((int*)(*a)->content != (int*)(*solved)->content)
		r_op(solved, 0);
	r_op(a, 'a');
}

void	indexer(t_stack **a2, t_stack **solved)
{
	t_stack *solving;
	t_stack *a;
	int index;

	a = *a2;
	while (a)
	{
		index = 1;
		solving = *solved;
		while (a->content != solving->content)
		{
			solving = solving->next;
			index++;
		}
		a->content = &index;
		a = a->next;
	}
}