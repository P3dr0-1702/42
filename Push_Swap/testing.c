/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:04:22 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/25 17:53:15 by pfreire-         ###   ########.fr       */
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
	int i =  last_val(*a);
	if (*(int *)(*b)->content > *(int *)(*a)->content
		|| *(int *)(*b)->content < i)
		p_op(b, a, 'b');
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
		ft_printf("Error\n");
		return (1);
	}
	a = string_to_stack(ft_split(join_args(argv), '|'));
	solved = non_ps_solver(&a);
	// indexer(&a, &solved);
	// indexer2(&solved);
	lis = list_lis(a);
	// print_list(&lis);
	// printf("\n");
	while (notmembers_of_lis(a, lis) > 0)
		move_cheapest_a2b(&a, &b, lis);
	while (!(check_stack_status(a, 0) && !(check_stack_status(b, 1))))
		move_cheapest_b2a(&a, &b, lis);
	breakpoint();
	i = 0;
	while ((!(check_stack_status(a, 0)) || b->next != NULL) && i < 1000000)
	{
		all_to_a(&a, &b);
		i++;
	}
	// print_list(&lis);
	// printf("\n");
	// print_stack(&b);
	// while (b)
}
