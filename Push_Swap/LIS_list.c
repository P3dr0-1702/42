/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:35:34 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/16 17:51:10 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

static t_list	*write_list(int *arr, int *prev, int last_index)
{
	t_list	*list;
	int		*val;

	list = NULL;
	while (last_index >= 0)
	{
		val = malloc(sizeof(int));
		if (!val)
			break ;
		*val = arr[last_index];
		ft_lstadd_front(&list, ft_lstnew(val));
		last_index = prev[last_index];
	}
	return (list);
}

t_list	*lis_tractor(t_stack *stack)
{
	int		*arr;
	int		*tails;
	int		*prev;
	int		lis_len;
	t_list	*lis;

	arr = stack_to_arr_conversion(stack);
	tails = malloc(sizeof(int) * ft_stacksize(stack));
	ft_bzero(tails, sizeof(int) * ft_stacksize(stack));
	prev = malloc(sizeof(int) * ft_stacksize(stack));
	ft_memset(prev, 0, sizeof(int) * ft_stacksize(stack));
	if (!arr || !tails || !prev)
		return (NULL);
	lis_len = fill_arr(arr, tails, prev, ft_stacksize(stack));
	lis = write_list(arr, prev, tails[lis_len - 1]);
	free(arr);
	free(tails);
	free(prev);
	return (lis);
}

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
			free_list(lis);
			lis = node;
		}
		else
			free_list(node);
		r_op(&stack, 0);
		k++;
	}
	return (lis);
}
