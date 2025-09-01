/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:58:19 by pfreire-          #+#    #+#             */
/*   Updated: 2025/09/01 18:25:07 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdbool.h>

bool	only_nbrs(char *a)
{
	int	i;

	i = 0;
	while (a[i] != '\0')
	{
		if (a[i] > '9' || a[i] < '0')
			return (false);
		i++;
	}
	return (true);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

bool	less_than_max(char *argv)
{
	int	i;

	i = ft_atoi(argv);
	if (i == -1)
		return (false);
	return (true);
}

bool	isvalid(char **argv)
{
	int	i;

	i = 1;
	while (i <= 5)
	{
		if (!argv[i] && i != 5)
			return (false);
		if (!argv[i] && i == 5)
			return (true);
		if (!only_nbrs(argv[i]) || !less_than_max(argv[i]))
			return (false);
		i++;
	}
	return (true);
}
