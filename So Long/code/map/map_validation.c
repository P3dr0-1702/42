/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:18:53 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/14 11:01:34 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool	is_rectangle(char **map)
{
	size_t	i;
	int		j;

	i = ft_strlen(map[0]);
	j = 1;
	while (map[j] != NULL)
	{
		if (i != ft_strlen(map[j]))
			return (false);
		j++;
	}
	return (true);
}

bool	one_word_one(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (str[0] == '1' && str[i - 1] == '1');
}

bool	only_ones(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(str);
	while (i < size)
	{
		if (str[i] != '1' && str[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

bool	is_closed(char *map)
{
	int		i;
	char	**maparr;
	bool	rectangular;

	i = 0;
	maparr = ft_split(map, '\n');
	if (!maparr)
		return (free_grid(maparr), false);
	if (!only_ones(maparr[0]))
		return (free_grid(maparr), false);
	while (maparr[i] != NULL)
	{
		if (!(one_word_one(maparr[i])))
			return (free_grid(maparr), false);
		i++;
	}
	i--;
	if (!only_ones(maparr[i]))
		return (free_grid(maparr), false);
	rectangular = is_rectangle(maparr);
	free_grid(maparr);
	return (rectangular);
}

t_point	p_coord(char **s)
{
	int		x;
	int		y;
	t_point	point;

	x = 0;
	y = 0;
	point.x = -1;
	point.y = -1;
	while (s[y])
	{
		x = 0;
		while (s[y][x])
		{
			if (s[y][x] == 'P')
			{
				point.x = x;
				point.y = y;
				return (point);
			}
			x++;
		}
		y++;
	}
	return (point);
}
