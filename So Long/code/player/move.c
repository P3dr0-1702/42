/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:48:19 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/11 10:05:53 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
		ft_printf("Total moves: %d\n", s->player.moves);
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
		ft_printf("Total moves: %d\n", s->player.moves);
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
		ft_printf("Total moves: %d\n", s->player.moves);
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
		ft_printf("Total moves: %d\n", s->player.moves);
		collected(s);
	}
	return (0);
}
