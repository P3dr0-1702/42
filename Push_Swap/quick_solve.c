/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:53:01 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/08 18:55:07 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

static void	quick_solve_2(t_stack *a)
{
	if (!is_stack_solved(a, 0))
		s_op(&a, 'a');
	return ;
}

static void	quick_solve_3(t_stack *a)
{
	if (is_stack_solved(a, 0))
		return ;
	if (*(int *)a->content == 1)
	{
		r_op(&a, 'a');
		s_op(&a, 'a');
	}
	else if (*(int *)a->content == 2)
	{
		if (*(int *)a->next->content == 3)
			rr_op(&a, 'a');
		else
			s_op(&a, 'a');
	}
	else if (*(int *)a->content == 3)
	{
		if (*(int *)a->next->content == 1)
			r_op(&a, 'a');
		else
		{
			s_op(&a, 'a');
			rr_op(&a, 'a');
		}
	}
}

void	quick_solve(t_stack *a)
{
	if (ft_stacksize(a) == 2)
		quick_solve_2(a);
	if (ft_stacksize(a) == 3)
		quick_solve_3(a);
}
