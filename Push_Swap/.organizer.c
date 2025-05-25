/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:38:47 by pfreire-          #+#    #+#             */
/*   Updated: 2025/05/25 16:36:34 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

int	hydra_ation(t_stack *solved)
{
	int	count;
	int	i;

	if(!solved)
		return(-1);
	count = ft_lstsize(solved);
	i = 0;
	while (i < count / 2)
		solved = solved->next;
	return ((int)solved->content);
}

void moving_pivot(t_stack **a, t_stack **b, t_stack **solved)
{
	int pivot;
	int i;
	int size;

	i = 0;
	pivot = hydra_ation(*solved);
	size = ft_lstsize(*a);
	while (i < size)
	{
		if ((int)(*a)->content < pivot)
			p_op(b, a, 'b');
		i++;
	}
}

int feeling_lucky(t_stack **a, t_stack **b)
{
	int a_solved;
	int b_solved;

	a_solved = 0;
	b_solved = 0;
	if(check_stack_status(a, 0))
		a_solved = 1;
	if(check_stack_status(b, 1))
		b_solved = 1;
	if(a_solved && b_solved)
	{
		while(ft_lstsize(b) > a_solved)
		{
			p_op(a, b, 'a');
			a_solved++;
		}
		return (0);
	}
	
	return(a_solved || b_solved);
}

void	legal_solver(t_stack **a, t_stack **b, t_stack **solved)
{
	int i;

	i = 0;
	moving_pivot(a,b, solved);
	while(!check_stack_status(*a,0) || !check_stack_status(*b, 1))
	{
		
	}
}
