/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:04:22 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/13 16:24:23 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"
#include "stdlib.h"

int	main(void)
{
	int		*i;
	int		k;
	t_stack	*head;
	t_stack *headb;
	t_stack	*node;
	t_stack **solved;
	t_stack	**stack;
	k = 0;
	head = NULL;
	headb = NULL;
	node = NULL;
	stack = &head;
	solved = &headb;
	while (k < 10)
	{
		i = malloc(sizeof(int));
		*i = rand() % rand();
		//printf("%d ", *i);
		node = ft_stacknew(i);
		ft_stackadd_back(stack, node);
		k++;
	}
	*solved = illegal_solver(&head);
	indexer(stack, solved);
	indexer2(solved);

	print_stack(stack);
	
	organizer(stack, solved);
}
