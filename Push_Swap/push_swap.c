/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:05:08 by pfreire-          #+#    #+#             */
/*   Updated: 2025/05/15 16:33:42 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

int main(int argc, char **argv)
{
	t_stack *arr_a;
	t_stack *arr_b;
	
	if(!(is_valid(argv)))
		return(printf("Error\n"), 0);
	arr_b = mklst(argv, arr_a);
}
