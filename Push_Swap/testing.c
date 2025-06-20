/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:04:22 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/20 10:56:13 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"
#include "stdlib.h"

int	main(void)
{
	int		*i;
	int		k;
	t_stack	*head;
	t_stack	*headb;
	t_stack	*node;
	t_stack	**solved;
	t_stack	**stack;
	t_list	*LIS;
	t_list	*newtry;
	t_stack	*headbs;
	t_stack	**b;

	k = 0;
	head = NULL;
	headb = NULL;
	node = NULL;
	stack = &head;
	solved = &headb;
	while (k < 1000)
	{
		i = malloc(sizeof(int));
		*i = rand() % rand();
		// printf("%d ", *i);
		node = ft_stacknew(i);
		ft_stackadd_back(stack, node);
		k++;
	}
	// print_stack(stack);
	// printf("\n");
	*solved = illegal_solver(&head);
	// print_stack(solved);
	// printf("\n");
	indexer(stack, solved);
	indexer2(solved);
	// print_stack(stack);
	// printf("\n");
	// printf("-------------------------------------");
	// printf("\n");
	// print_stack(solved);
	LIS = NULL;
	k = 0;
	while (k < ft_stacksize(*stack))
	{
		newtry = lis_tractor(*stack);
		if (ft_lstsize(newtry) > ft_lstsize(LIS))
		{
			LIS = newtry;
		}
		r_op(stack, 0);
		k++;
	}
	print_stack(stack);
	printf("\n\n");
	// printf("\n");
	// printf("\n");
	// print_list(&LIS);
	// printf("\n");
	// printf("\n");
	headbs = NULL;
	b = &headbs;
	while (notmembers_of_LIS(*stack, LIS) > 0)
		move_cheapest(stack, b, LIS);
	// print_stack(stack);
	// printf("\n");
	// printf("\n");
	// printf("\n");
}
