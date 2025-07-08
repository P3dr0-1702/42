/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:23:42 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/08 14:14:46 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_tile(t_game *g, t_image *tile, unsigned int color, int *coords)
{
	int	ty;
	int	tx;

	ty = 0;
	while (ty < tile->height)
	{
		tx = 0;
		while (tx < tile->width)
		{
			color = pixel_get(tile, tx, ty);
			ft_pixel_put(g, coords[0] + tx, coords[1] + ty, color);
			tx++;
		}
		ty++;
	}
}

void	render_player_buffer(t_game *game)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < game->player.sprite.height)
	{
		x = 0;
		while (x < game->player.sprite.width)
		{
			color = pixel_get(&game->player.sprite, x, y);
			if ((color >> 24) != 0xFF)
			{
				ft_pixel_put(game, game->player.coord.x + x + 32, game->player.coord.y + y,
					color);
			}
			x++;
		}
		y++;
	}
}

void	render_base_buffer(t_game *s)
{
	int				i;
	int				coords[2];
	unsigned int	color;
	t_image			tile;

	i = 0;
	color = 0;
	coords[0] = 0;
	coords[1] = 0;
	while (s->map.map[i] != '\0')
	{
		if (s->map.map[i] != '\n')
		{
			tile = init_tile(s, i);
			fill_tile(s, &tile, color, coords);
		}
		coords[0] += tile.width;
		if (s->map.map[i] == '\n')
		{
			coords[1] += tile.height;
			coords[0] = 0;
		}
		i++;
	}
}

void	render_frame(t_game *s, int playerx, int playery)
{
	s->player.coord.x = playerx;
	s->player.coord.y = playery;
	render_base_buffer(s);
	render_player_buffer(s);
	mlx_put_image_to_window(s->win.mlx_ptr, s->win.win_ptr,
		s->win.frame_buffer.img_ptr, 0, 0);
}
