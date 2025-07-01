/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:22:25 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/01 14:28:15 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

static int	error(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*solved;
	t_list	*lis;

	a = NULL;
	b = NULL;
	solved = NULL;
	lis = NULL;
	if (argc == 1)
		return (-1);
	if (!is_valid_input(argv))
		return (error());
	a = string_to_stack(ft_split(join_args(argv), '|'));
	if(!a)
		return(error());
	if (has_dulicate(a))
		return (error());
	solved = stack_solver(&a);
	indexer(&a, &solved);
	free(solved);
	lis = list_lis(a);
	solver(a, b, lis);
	return (free(a), free(b), free(lis), 0);
}
