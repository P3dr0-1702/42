/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:04:22 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/01 10:29:24 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"
#include "stdlib.h"

t_list	*list_lis(t_stack *stack)
{
	t_list	*node;
	int		k;
	t_list	*lis;

	lis = NULL;
	node = NULL;
	k = 0;
	while (k < ft_stacksize(stack))
	{
		node = lis_tractor(stack);
		if (ft_lstsize(node) > ft_lstsize(lis))
		{
			lis = node;
		}
		r_op(&stack, 0);
		k++;
	}
	return (lis);
}

int	check_stack_status(t_stack *a, int is_reverse)
{
	int	k;

	k = 0;
	while (a->next != NULL || k < ft_stacksize(a) + 1)
	{
		if (is_reverse)
		{
			if (*(int *)a->content < *(int *)a->next->content)
				return (0);
		}
		else
		{
			if (*(int *)a->content > *(int *)a->next->content)
				return (0);
		}
		a = a->next;
		k++;
	}
	return (1);
}

int	last_val(t_stack *a)
{
	t_stack	*target;

	target = a;
	if (target->next)
	{
		while (target->next)
		{
			target = target->next;
		}
		return (*(int *)target->content);
	}
	else
		return (*(int *)target->content);
}

void	all_to_a(t_stack **a, t_stack **b)
{
	int	i;
	int	bval;

	i = last_val(*a);
	bval = *(int *)(*b)->content;
	if (bval == *(int *)(*a)->content - 1)
		p_op(b, a, 'a');
	else
		rr_op(a, 'a');
}

int	does_b_exist(t_stack *b)
{
	if (b || b->next)
		return (1);
	return (0);
}
void	breakpoint(void)
{
	return ;
}

int	check_b(t_stack *b)
{
	t_stack	*temp;

	temp = b;
	while (temp->prev)
		temp = temp->prev;
	if (temp->next)
		return (0);
	else
		return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*solved;
	t_list	*lis;
	int		i;

	a = NULL;
	b = NULL;
	solved = NULL;
	lis = NULL;
	if (!valid_input(argv) || argc == 1)
	{
		if (argc == 1)
			return (-1);
		ft_printf("Error\n");
		return (1);
	}
	a = string_to_stack(ft_split(join_args(argv), '|'));
	solved = non_ps_solver(&a);
	indexer(&a, &solved);
	indexer2(&solved);
	lis = list_lis(a);
	// print_list(&lis);
	// printf("\n");
	while (notmembers_of_lis(a, lis) > 0)
		move_cheapest_a2b(&a, &b, lis);
	while (!(check_stack_status(a, 0)))
		move_cheapest_b2a(&a, &b, lis);
	while (!(check_stack_status(b, 1)))
		r_op(&b, 'b');
	// breakpoint();
	i = 0;
	if (last_val(a) < *(int *)b->content)
		p_op(&b, &a, 'a');
	while (b)
	{
		all_to_a(&a, &b);
		i++;
	}
	// p_op(&b, &a, 'a');
	// print_list(&lis);
	// printf("\n");
	// print_stack(&b);
	// while (b)
}
