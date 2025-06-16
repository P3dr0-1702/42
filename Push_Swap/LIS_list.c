/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:35:34 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/16 17:10:14 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

int	*stack_to_arr_conversion(t_stack *stack)
{
	int	*arr;
	int	i;
	int	size;

	size = ft_stacksize(stack);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (stack && i < size)
	{
		arr[i] = *(int *)stack->content;
		stack = stack->next;
		i++;
	}
	return (arr);
}

int	fill_arr(int *arr, int *tails, int *prev, int size)
{
	int	i;
	int	start;
	int	end;
	int	meio;
	int	lis_len;

	i = -1;
	lis_len = 0;
	while (++i < size)
	{
		start = 0;
		end = lis_len;
		while (start < end)
		{
			meio = (start + end) / 2;
			if (arr[tails[meio]] < arr[i])
				start = meio + 1;
			else
				end = meio;
		}
		if (start == lis_len)
			lis_len++;
		tails[end] = i;
		prev[i] = -1;
		if (start > 0)
			prev[i] = tails[start - 1];
	}
	return (lis_len);
}

t_list	*write_list(int *arr, int *prev, int last_index)
{
	t_list	*list;
	int		*val;

	list = NULL;
	while (last_index > 0)
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
	prev = malloc(sizeof(int) * ft_stacksize(stack));
	if (!arr || !tails || !prev)
		return (NULL);
	lis_len = fill_arr(arr, tails, prev, ft_stacksize(stack));
	lis = write_list(arr, prev, tails[lis_len - 1]);
	free(arr);
	free(tails);
	free(prev);
	return (lis);
}
