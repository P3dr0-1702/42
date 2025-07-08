/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:22:25 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/08 18:04:55 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

static int	error(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

static int	error_manager(char **arg_v)
{
	if (!is_valid_input(arg_v))
		error();
	return (-1);
}

static int	free_main(t_stack *a, t_list *lis, char **temp, char *str)
{
	free_stack(a);
	free_list(lis);
	free_arr((void **)temp);
	free(str);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*lis;
	char	**temp;
	char	*str_temp;

	a = NULL;
	b = NULL;
	lis = NULL;
	if (argc == 1 || !is_valid_input(argv))
		return (error_manager(argv));
	str_temp = join_args(argv);
	temp = ft_split(str_temp, '|');
	a = string_to_stack(temp);
	if ((!a || has_dulicate(a)) || !within_bounds(temp))
		return (free_main(a, lis, temp, str_temp), error());
	b = stack_solver(&a);
	indexer(&a, &b);
	free_stack(b);
	b = NULL;
	lis = list_lis(a);
	solver(a, b, lis);
	return (free_main(a, lis, temp, str_temp));
}
