/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:40:58 by pfreire-          #+#    #+#             */
/*   Updated: 2025/05/15 17:50:32 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

void	s_op(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*temp2;
	void	*rando;

	temp = lst;
	temp2 = temp->next;
	rando = temp->content;
	temp->content = temp2->content;
	temp2->content = rando;
}

void	p_op(t_stack **b, t_stack **a)
{
	t_stack *tempa;

	tempa = *a;
	if (*a)
		(*a)->prev = NULL;

	tempa->next = *b;
	if (*b)
		(*b)->prev = tempa;

	tempa->prev = NULL;
	*b = tempa;
}

void r_op(t_stack **a)
{
	t_stack *first;
	t_stack *second;

	first = *a;
	*a = (*a)->next;
	second = *a;

	while(second->next)
		second = second->next;
	
	second->next = first;
	first->next = NULL;
}

void rr_op(t_stack **a)
{
	t_stack *prev;
	t_stack *last;

	prev = NULL;
	last = *a;
	while(last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
}