/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:27:22 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/14 12:04:48 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool	should_put_wall(char *map, int i)
{
	if (i == 0)
	{
		if ((map[i + 1] == '\n' || map[i + 1] == '\0' || i == 0) || (map[i
					+ 1] == '1' && (i < is_top(map) || i > is_bottom(map))))
			return (true);
	}
	if (i == my_strlen(map))
	{
		if (map[i - 1] == '\n' || i == 0 || ((map[i + 1] == '1' && map[i
						- 1] == '1') && (i < is_top(
						map) || i > is_bottom(map))))
			return (true);
	}
	if ((map[i - 1] == '\n' || map[i + 1] == '\n' || map[i + 1] == '\0'
			|| i == 0) || ((map[i + 1] == '1' && map[i - 1] == '1')
			&& (i < is_top(map) || i > is_bottom(map))))
		return (true);
	return (false);
}

char	pick_obstacle(void)
{
	int	temp_rn;

	temp_rn = rng() % 10;
	if (temp_rn == 1)
		return (OCTUPUSS);
	else if (temp_rn > 5)
		return (DESTROYED_GROUND);
	else
		return (BOX);
}

char	pick_wall(char *map, int i)
{
	if (is_first_line(map, i) && rng() % 7 == 1)
		return (WALL_POSTER);
	else if (is_first_line(map, i) && rng() % 3 == 0)
		return (WALL_PANEL);
	else if (should_put_wall(map, i) && rng() % 100 == 5)
		return (KOJIMA_WALL);
	else if (should_put_wall(map, i) && rng() % 3 == 1)
		return (WALL_SIGN);
	else if (should_put_wall(map, i))
		return (WALL);
	else
		return (pick_obstacle());
}

char	pick_ground(char *map, int i)
{
	int	temp_rn;

	if (map[i] != '0')
		return (0);
	if (rng() % 100 == 1)
		return (GROUND2);
	else if (rng() % 100 < 66)
	{
		temp_rn = rng() % 3;
		if ((temp_rn == 0) && (rng() % 3 == 0))
			return (GROUND4);
		else if (temp_rn == 1)
			return (GROUND3);
	}
	return (GROUND1);
}

char	*store_map(char *map)
{
	int		i;
	int		x;
	int		y;
	char	*str;

	i = 0;
	x = 0;
	y = 0;
	if (!map)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(map) + 1));
	if (!str)
		return (free(map), ft_printf("Could not store map\n"), NULL);
	while (map[i] != '\0')
	{
		if (map[i] == '1')
			str[i] = pick_wall(map, i);
		else if (map[i] == '0')
			str[i] = pick_ground(map, i);
		else
			str[i] = map[i];
		i++;
	}
	str[i] = '\0';
	return (free(map), str);
}
