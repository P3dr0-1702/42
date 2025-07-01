/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sops.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:54:38 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/16 17:11:18 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

void	ss_sop(t_stack **a, t_stack **b)
{
	s_op(a, 0);
	s_op(b, 0);
	ft_printf("ss\n");
}

void	rr_sop(t_stack **a, t_stack **b, char *print)
{
	r_op(a, 0);
	r_op(b, 0);
	if (print)
		ft_printf("r%s\n", print);
}

void	rrr_sop(t_stack **a, t_stack **b, char *print)
{
	rr_op(a, 0);
	rr_op(b, 0);
	if (print)
		ft_printf("r%s\n", print);
}
