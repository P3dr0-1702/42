/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:07:19 by pfreire-          #+#    #+#             */
/*   Updated: 2025/05/25 18:14:33 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

void legal_solver(t_stack **a, t_stack **b, t_stack **solved)
{
	int is_reverse;
	int index;

	p_op(b, a, 'b');
	while(check_stack_status(a, 0) && !b)
	{
		if(is_reverse = (index = find_target((int)(*a)->content, solved), ft_lstsize(solved)))
		{
			rotate(a, b, solved, index, is_reverse);
		}
	}
}