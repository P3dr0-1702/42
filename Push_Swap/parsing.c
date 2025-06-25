/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:56:05 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/25 15:30:31 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_func.h"

static bool	is_aldigit(char *s)
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

bool	valid_input(char **argv)
{
	int		j;

	j = 1;
	while (argv[j])
	{
		if (!is_aldigit(argv[j]))
			return (false);
		j++;
	}
	return (true);
}

static int	arr_len(char **ar)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (ar[i])
	{
		count += ft_strlen(ar[i]);
		i++;
		count++;
	}
	return (count);
}

char	*join_args(char **argv)
{
	int		i;
	int		j;
	int		s;
	char	*str;

	str = malloc(sizeof(char) * arr_len(argv));
	j = 1;
	s = 0;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (argv[j][i] == ' ')
				str[s] = '|';
			else
				str[s] = argv[j][i];
			s++;
			i++;
		}
		str[s++] = '|';
		j++;
	}
	str[s - 1] = '\0';
	return (str);
}

t_stack	*string_to_stack(char **slitted)
{
	t_stack	*node;
	t_stack	*head;
	int		k;
	int		*i;

	node = NULL;
	head = NULL;
	k = 0;
	while (slitted[k] != NULL)
	{
		i = malloc(sizeof(int));
		*i = ft_atoi(slitted[k]);
		node = ft_stacknew(i);
		ft_stackadd_back(&head, node);
		k++;
	}
	return (head);
}
