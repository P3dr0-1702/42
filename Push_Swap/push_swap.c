/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:05:08 by pfreire-          #+#    #+#             */
/*   Updated: 2025/05/29 16:22:41 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

int main(int argc, char **argv)
{
	t_stack *arr_a;
	t_stack *arr_b;
	t_stack *solved;
	
	if(!(is_valid(argv)))
		return(printf("Error\n"), 0);
	arr_b = mklst(argv, arr_a);
	solved = illegal_solver(arr_a);
	indexer(arr_a, solved);
	legal_solver(arr_a, arr_b, solved);
}
