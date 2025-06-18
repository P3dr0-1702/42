/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:44:17 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/18 16:42:32 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

void	s_op(t_stack **lst, char is_a)
{
	t_stack	*temp;
	t_stack	*temp2;
	void	*rando;

	if (!lst || !*lst || !((*lst)->next))
		return ;
	temp = *lst;
	temp2 = temp->next;
	rando = temp->content;
	temp->content = temp2->content;
	temp2->content = rando;
	if (is_a)
		ft_printf("s%c\n", is_a);
}

void	p_op(t_stack **from, t_stack **to, char is_a)
{
	t_stack	*tempa;

	if (!(*from))
		return ;
	tempa = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	tempa->next = *to;
	if (*to)
		(*to)->prev = tempa;
	tempa->prev = NULL;
	*to = tempa;
	if (is_a)
		ft_printf("p%c\n", is_a);
}

void	r_op(t_stack **a, char is_a)
{
	t_stack	*first;
	t_stack	*second;

	if (!a || !(*a) || !((*a)->next))
		return ;
	first = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	second = *a;
	while (second->next)
		second = second->next;
	second->next = first;
	first->prev = second;
	first->next = NULL;
	if (is_a)
		ft_printf("r%c\n", is_a);
}

void	rr_op(t_stack **a, char is_a)
{
	t_stack	*last;

	if (!a || !(*a) || !((*a)->next))
		return ;
	last = *a;
	while (last->next)
		last = last->next;
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = *a;
	(*a)->prev = last;
	*a = last;
	if (is_a)
		ft_printf("rr%c\n", is_a);
}
