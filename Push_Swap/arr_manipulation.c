/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:27:20 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/16 15:18:31 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

// usado para criar a LIS

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

int	fill_prev(int *prev, int *tails, int start, int i)
{
	if (start > 0)
		prev[i] = tails[start - 1];
	else
		prev[i] = -1;
	return (i);
}

int	fill_arr(int *arr, int *tails, int *prev, int size)
{
	int	i;
	int	start;
	int	lis_len;

	i = -1;
	lis_len = 0;
	while (++i < size)
	{
		start = 0;
		while (start < lis_len && arr[tails[start]] < arr[i])
			start++;
		if (start == lis_len)
			lis_len++;
		tails[start] = fill_prev(prev, tails, start, i);
	}
	return (lis_len);
}
