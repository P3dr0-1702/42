/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:38:03 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/12 12:07:37 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_image	init_tile_base(t_game *s, int i)
{
	t_image	tile;

	tile.img_ptr = which_sprite(s, i);
	if (!tile.img_ptr)
	{
		ft_printf("Failed to load Base assets.\n");
		close_game(s);
	}
	tile.img_addr = mlx_get_data_addr(tile.img_ptr, &tile.bpp, &tile.l_len,
			&tile.endian);
	tile.width = 128;
	tile.heigth = 128;
	return (tile);
}

void	fill_tile(t_game *g, t_image *tile, unsigned int color, t_point point)
{
	int	ty;
	int	tx;

	ty = 0;
	while (ty < tile->heigth)
	{
		tx = 0;
		while (tx < tile->width)
		{
			color = pixel_get(tile, tx, ty);
			if ((color >> 24) != 0xFF)
				ft_pixel_put(&g->base, point.x + tx, point.y + ty, color);
			tx++;
		}
		ty++;
	}
}

void	init_base(t_game *s)
{
	int				i;
	t_image			tile;
	t_point			point;
	unsigned int	color;

	i = 0;
	color = 0;
	point.x = 0;
	point.y = 0;
	while (s->map.map[i] != '\0')
	{
		if (s->map.map[i] != '\n')
		{
			tile = init_tile_base(s, i);
			fill_tile(s, &tile, color, point);
			mlx_destroy_image(s->mlx_ptr, tile.img_ptr);
			point.x += 128;
		}
		else
		{
			point.y += 128;
			point.x = 0;
		}
		i++;
	}
}
