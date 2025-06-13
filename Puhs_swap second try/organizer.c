/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:46:32 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/13 17:54:45 by pfreire-         ###   ########.fr       */
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

	head = a;
	tails = 0;
	heads = 0;
	members = NULL;
	while(heads < ft_stacksize(a))
	{
		tail = head->next;
		while(tails < ft_stacksize(a))
		{
			if(bodyguard(members, head, tail, 0) < bodyguard(members, head, tail->next, 0))
				bodyguard(members, head, tail, 1);
			tails++;
			tail = tail->next;
		}
		heads++;
		head = head->next;
	}
	return (members);
}

int bodyguard(t_stack *members, t_stack *heads, t_stack *tails, int write_to_members)
{
	int min;
	int max;
	t_stack *node;
	int curr;

	min = *(int*)heads->content;
	max = *(int*)tails->content;
	curr = 0;
	while(tails)
	{
		if(*(int*)tails->content > min && *(int*)tails->content <= max)
		{
			node = ft_stacknew(*(int*)tails->content);
			min = *(int*)tails->content;
			if(write_to_members)
				ft_stackadd_back(members, node);
			curr++;
		}
		tails = tails->next;
	}
	return (curr);
}
