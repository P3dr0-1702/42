/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:45:24 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/14 17:34:45 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collected(t_game *s)
{
	t_point	*player;
	t_point	collectibles;
	int		i;

	i = 0;
	player = &s->player.coord;
	while (i < s->collectibles.count)
	{
		collectibles = s->collectibles.collectible[i].coord;
		if (player->tile_x == collectibles.tile_x && player->tile_y == collectibles.tile_y)
		{
			s->collectibles.collectible[i].active = false;
			s->player.collectibles++;
		}
		i++;
		if (i > 1000)
			break ;
	}
}

int	move_up(t_game *s)
{
	int	x;
	int	y;

	x = s->player.coord.x / 128;
	y = s->player.coord.y / 128;
	if (s->map.grid[y - 1][x] != '1')
	{
		s->player.coord.tile_y--;
		s->player.coord.y -= 128;
		s->player.moves++;
		collected(s);
	}
	return (0);
}

int	move_down(t_game *s)
{
	int	x;
	int	y;

	x = s->player.coord.x / 128;
	y = s->player.coord.y / 128;
	if (s->map.grid[y + 1][x] != '1')
	{
		s->player.coord.tile_y++;
		s->player.coord.y += 128;
		s->player.moves++;
		collected(s);
	}
	return (0);
}
int	move_left(t_game *s)
{
	int	x;
	int	y;

	x = s->player.coord.x / 128;
	y = s->player.coord.y / 128;
	if (s->map.grid[y][x - 1] != '1')
	{
		s->player.coord.tile_x--;
		s->player.coord.x -= 128;
		s->player.moves++;
		collected(s);
	}
	return (0);
}
int	move_right(t_game *s)
{
	int	x;
	int	y;

	x = s->player.coord.x / 128;
	y = s->player.coord.y / 128;
	if (s->map.grid[y][x + 1] != '1')
	{
		s->player.coord.tile_x++;
		s->player.coord.x += 128;
		s->player.moves++;
		collected(s);
	}
	return (0);
}
