/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:24:30 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/08 18:08:05 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

bool	has_dulicate(t_stack *stack)
{
	t_stack	*outer;
	t_stack	*inner;
	int		val;

	outer = stack;
	if (!stack)
		return (true);
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

bool	bounds(char *str)
{
	int		i;
	int		sign;
	int		j;
	char	*limit;

	sign = 1;
	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	limit = limits(sign);
	j = 0;
	while (j < 10 && ft_strlen(str) > 10)
	{
		if (str[i + j] > limit[j])
			return (false);
		j++;
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

bool	within_bounds(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!bounds(str[i]) || ft_strlen(str[i]) > 10)
			return (false);
		i++;
	}
	return (true);
}
