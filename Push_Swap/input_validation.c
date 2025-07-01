/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:24:30 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/01 13:56:59 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

bool	has_dulicate(t_stack *stack)
{
	t_stack	*outer;
	t_stack	*inner;
	int		val;

	outer = stack;
	while (outer)
	{
		val = *(int *)outer->content;
		inner = outer->next;
		while (inner)
		{
			if (*(int *)inner->content == val)
				return (true);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (false);
}

bool	is_alldigit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
		{
			i++;
			continue ;
		}
		if (s[i] == '-' || s[i] == '+')
		{
			if ((i > 0 && s[i - 1] != ' ') || !ft_isdigit(s[i + 1]))
				return (false);
			i++;
		}
		if (!ft_isdigit(s[i]))
			return (false);
		while (ft_isdigit(s[i]))
			i++;
	}
	return (true);
}

bool	is_valid_input(char **argv)
{
	int	j;

	j = 1;
	while (argv[j])
	{
		if (!is_alldigit(argv[j]))
			return (false);
		j++;
	}
	return (true);
}
