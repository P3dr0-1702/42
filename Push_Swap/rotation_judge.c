/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_judge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:18:27 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/01 11:43:41 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

void	rr_sop_multi(t_stack **a, t_stack **b, int *indexa, int *indexb)
{
	while (*indexa < 0 && *indexb < 0)
	{
		rrr_sop(a, b, "rr");
		(*indexa)++;
		(*indexb)++;
	}
	while (*indexa < 0)
	{
		rr_op(a, 'a');
		(*indexa)++;
	}
	while (*indexb < 0)
	{
		rr_op(b, 'b');
		(*indexb)++;
	}
}

void	r_sop_multi(t_stack **a, t_stack **b, int *indexa, int *indexb)
{
	while (*indexa > 0 && *indexb > 0)
	{
		rr_sop(a, b, "r");
		(*indexa)--;
		(*indexb)--;
	}
	while (*indexa > 0)
	{
		r_op(a, 'a');
		(*indexa)--;
	}
	while (*indexb > 0)
	{
		r_op(b, 'b');
		(*indexb)--;
	}
}

void	rotation_judge(t_stack **a, t_stack **b, int indexa, int indexb)
{
	int	siza;
	int	sizb;
	int	offseta;
	int	offsetb;

	siza = ft_stacksize(*a);
	sizb = ft_stacksize(*b);
	offseta = indexa;
	if ((indexa > siza / 2))
		offseta = (abs(indexa - siza)) * -1;
	offsetb = indexb;
	if ((indexb > sizb / 2))
		offsetb = (abs(indexb - sizb)) * -1;
	rr_sop_multi(a, b, &offseta, &offsetb);
	r_sop_multi(a, b, &offseta, &offsetb);
	p_op(a, b, 'b');
}

void	rotation_judge_nopush(t_stack **a, t_stack **b, int indexa, int indexb)
{
	int	siza;
	int	sizb;
	int	offseta;
	int	offsetb;

	siza = ft_stacksize(*a);
	sizb = ft_stacksize(*b);
	offseta = indexa;
	if ((indexa > siza / 2))
		offseta = (abs(indexa - siza)) * -1;
	offsetb = indexb;
	if ((indexb > sizb / 2))
		offsetb = (abs(indexb - sizb)) * -1;
	rr_sop_multi(a, b, &offseta, &offsetb);
	r_sop_multi(a, b, &offseta, &offsetb);
}