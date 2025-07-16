/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:17:04 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/11 11:11:53 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

int	abs(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

char	*limits(int sign)
{
	if (sign < 0)
		return ("2147483648");
	return ("2147483647");
}

int	is_stack_solved(t_stack *a, int is_reverse)
{
	int	k;

	k = 0;
	while (a->next != NULL)
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
