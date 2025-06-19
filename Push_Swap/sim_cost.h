/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_cost.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:32:30 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/19 17:54:43 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

void	sim_rotation_judge(t_stack **b, int index, int *cost)
{
	int	size;

	size = ft_stacksize(*b);
	if (index <= size / 2)
	{
		while (index > 0)
		{
			r_op(b, 0);
			index--;
			(*cost)++;
		}
	}
	else
	{
		index = ft_stacksize(*b) - index;
		while (index > 0)
		{
			rr_op(b, 0);
			index--;
			(*cost)++;
		}
	}
}

int	sim_bouncer(t_stack *a, t_stack *b, t_list *LIS)
{
	
}
