/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:35:26 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/17 13:42:11 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
void	direction(int dir, int target_x, int target_y)
{
	target_x = 0;
	target_y = 0;
	if (dir == 0)
		target_x = -1;
	else if (dir == 1)
		target_y = -1;
	else if (dir == 2)
		target_x = 1;
	else if (dir == 3)
		target_y == 1;
}

int	move(t_game *s, int dir)
{
	int	x;
	int	y;
	int	x_target;
	int	y_target;

	x = s->player.coord.x / 128;
	y = s->player.coord.y / 128;
	direction(&dir, &x_target, &y_target);
	if (s->map.grid[y + y_target][x + x_target] != '1')
	{
		s->player.coord.tile_y += y_target;
		s->player.coord.tile_x += x_target;
		s->player.moves++;
		collected(s);
	}
}
