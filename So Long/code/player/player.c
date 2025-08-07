/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:35:26 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/07 14:03:34 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_point	exit_pos(char *str)
{
	t_point	point;
	int		i;

	i = 0;
	point.y = 0;
	point.x = 0;
	while (str[i] != 'E')
	{
		point.x++;
		if (str[i] == '\n')
		{
			point.y++;
			point.x = 0;
		}
		i++;
	}
	return (point);
}

bool	game_win(t_game *s)
{
	if (s->player.collectibles == s->collectibles.count)
	{
		if (s->player.coord.tile_x == exit_pos(s->map.map).x
			&& s->player.coord.tile_y == exit_pos(s->map.map).y)
			return (true);
	}
	return (false);
}

void	collected(t_game *s)
{
	t_point	*player_pos;
	t_point	collectibles;
	int		i;

	i = 0;
	player_pos = &s->player.coord;
	while (i < s->collectibles.count)
	{
		collectibles = s->collectibles.collectible[i].coord;
		if (s->collectibles.collectible[i].active
			&& (player_pos->tile_x == collectibles.tile_x
				&& player_pos->tile_y == collectibles.tile_y))
		{
			s->collectibles.collectible[i].active = false;
			s->player.collectibles++;
		}
		i++;
	}
}

void	direction(int dir, int *target_x, int *target_y)
{
	if (dir == 0)
		*target_x = -1;
	else if (dir == 1)
		*target_y = -1;
	else if (dir == 2)
		*target_x = 1;
	else if (dir == 3)
		*target_y = 1;
}
