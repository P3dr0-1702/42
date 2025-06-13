/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:46:32 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/13 17:36:24 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

void	organizer(t_stack **g, t_stack **solved)
{
	t_stack	*a;
	t_stack	*solving;
	t_stack	*b;
	t_stack *temp;

	a = *g;
	solving = *solved;
	b = NULL;
	temp = NULL;
	//print_stack(&a);
	while (*(int *)a->content != *(int *)solving->content)
		r_op(&solving, 0);
	rr_sop(&a, &solving, "a");
	//print_stack(&a);
	while (!(check_stack_status(a, 0)) && b)
	{
		comparator(&a, &b, &solving);
		//printf("A");
		rr_sop(&a, &solving, "a");
	}

}

void	comparator(t_stack **a, t_stack **b, t_stack **solving)
{
	if (*(int *)(*a)->content != *(int *)(*solving)->content)
	{
		p_op(a, b, 'b');
		r_op(solving, 0);
		rotator(a, b, solving);
	}
}

void	rotator(t_stack **a, t_stack **b, t_stack **solving)
{
	int	OGcurr;
	int curr;

	OGcurr = *(int *)(*b)->content;
	curr = OGcurr;
	//printf("0");
	while (OGcurr != *(int *)(*solving)->content)
	{
		if (*(int *)(*a)->content == curr + 1 || *(int *)(*a)->content == curr)
		{
			curr = *(int *)(*a)->content;
			p_op(a, b, 'a');
		}
		rr_sop(a, solving, "a");
	}
	while((*b))
	{
		p_op(b, a, 'a');
		rr_op(solving, 0);
	}
}

t_stack *LIS_list(t_stack *a)
{
	t_stack *head;
	t_stack *tail;
	int heads;
	int tails;
	t_stack *members;

	head = 1;
	head = a;
	tail = a;
	members = NULL;
	while(heads < ft_stacksize(a))
	{
		tail = head->next;
		while(tails < ft_stacksize(a))
		{
			bodyguard(members, head, tail, *(int*)head->content, *(int*)tail->content);
			tails++;
			tail = tail->next;
		}
		heads++;
	}
}

void bodyguard(t_stack *members, t_stack *heads, t_stack *tails, int min, int max)
{
	if(*(int*)heads->content > min)
	{
		
	}
}
