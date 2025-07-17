/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:45:24 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/17 10:16:36 by pfreire-         ###   ########.fr       */
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
		if (player->tile_x == collectibles.tile_x
			&& player->tile_y == collectibles.tile_y)
		{
			s->collectibles.collectible[i].active = false;
			s->player.collectibles++;
		}
		i++;
		if (i > 1000)
			break ;
	}
}

void	dir(int *dir, int *target_x, int *target_y)
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
		if (s->map.grid[y + y_target][x + x_target] != '1')
	{
		s->player.coord.tile_y += y_target;
		s->player.coord.tile_x += x_target;
		s->player.coord.x += x_target *128;
		s->player.coord.y += y_target * 128;
		s->player.moves++;
		collected(s);
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
