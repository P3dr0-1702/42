/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:16:37 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/02 10:54:51 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

void	indexer(t_stack **a2, t_stack **solved)
{
	t_stack	*solving;
	t_stack	*a;
	int		index;
	int		*new_ind;

	a = *a2;
	while (a)
	{
		index = 1;
		solving = *solved;
		while (*(int *)a->content != *(int *)solving->content)
		{
			solving = solving->next;
			index++;
		}
		new_ind = malloc(sizeof(int));
		*new_ind = index;
		free(a->content);
		a->content = new_ind;
		a = a->next;
	}
}

void	indexer_solved(t_stack **solved2)
{
	t_stack	*solved;
	int		index;
	int		*new_ind;

	index = 1;
	solved = *solved2;
	while (solved)
	{
		new_ind = malloc(sizeof(int));
		*new_ind = index;
		free(solved->content);
		solved->content = new_ind;
		solved = solved->next;
		index++;
	}
}
