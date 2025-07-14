/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:59:30 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/14 17:46:34 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_game *s)
{
	s->player.sprite.img_ptr = mlx_xpm_file_to_image(s->mlx_ptr, s->player.anim,
			&s->player.sprite.width, &s->player.sprite.heigth);
	s->player.sprite.img_addr = mlx_get_data_addr(s->player.sprite.img_ptr,
			&s->player.sprite.bpp, &s->player.sprite.l_len,
			&s->player.sprite.endian);
}

t_image	init_tile_base(t_game *s, int i)
{
	t_image	tile;

	tile.img_ptr = which_sprite(s, i);
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
			point.x += tile.width;
		}
		else
		{
			point.y += tile.heigth;
			point.x = 0;
		}
		i++;
	}
}

int	char_count(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
	if (c == '\0')
		return (1);
	return (count);
}

void	init_collectible(t_collect *s, int x, int y)
{
	s->coord.x = x * 128;
	s->coord.y = y * 128;
	s->active = true;
	s->coord.tile_x = x;
	s->coord.tile_y = y;
}

void	init_collectibles(t_game *s)
{
	int	x;
	int	y;
	int	i;
	int	k;

	s->collectibles.collectible = malloc(sizeof(t_image) * s->collectibles.count);
	x = 0;
	y = 0;
	i = 0;
	k = 0;
	while (s->map.map[i] != '\0')
	{
		if (s->map.map[i] == 'C')
		{
			init_collectible(&s->collectibles.collectible[k], x, y);
			k++;
		}
		x++;
		if (s->map.map[i] == '\n')
		{
			x = 0;
			y++;
		}
		i++;
	}
}

void	init_game(t_game *s)
{
	s->win.ntilesx = xtile(s->map.map);
	s->win.ntilesy = ytile(s->map.map);
	s->win.width = 128 * xtile(s->map.map);
	s->win.height = 128 * ytile(s->map.map);
	s->win.win_ptr = mlx_new_window(s->mlx_ptr, s->win.width, s->win.height,
			"TAE: Metal Gear");
	s->map.grid = ft_split(s->map.map, '\n');
	s->map.map = store_map(s->map.map);
	s->win.frame_buffer.img_ptr = mlx_new_image(s->mlx_ptr, s->win.width,
			s->win.height);
	s->win.frame_buffer.img_addr = mlx_get_data_addr(s->win.frame_buffer.img_ptr,
			&s->win.frame_buffer.bpp, &s->win.frame_buffer.l_len,
			&s->win.frame_buffer.endian);
	s->win.frame_buffer.width = s->win.width;
	s->win.frame_buffer.heigth = s->win.height;
	s->base.img_ptr = mlx_new_image(s->mlx_ptr, s->win.width, s->win.height);
	s->base.img_addr = mlx_get_data_addr(s->base.img_ptr, &s->base.bpp,
			&s->base.l_len, &s->base.endian);
	s->base.width = s->win.width;
	s->base.heigth = s->win.height;
	s->player.coord.x = 0;
	s->player.coord.y = 0;
	s->player.anim = "assets/Boxed_SS1.xpm";
	s->debug_mode = false;
	s->player.moves = 0;
	s->collectibles.count = char_count(s->map.map, 'C');
	init_player(s);
	s->collectibles.sprite.img_ptr = mlx_xpm_file_to_image(s->mlx_ptr, "assets/Ration.xpm", &s->collectibles.sprite.width, &s->collectibles.sprite.heigth);
	s->collectibles.sprite.img_addr = mlx_get_data_addr(s->collectibles.sprite.img_ptr, &s->collectibles.sprite.bpp, &s->collectibles.sprite.l_len, &s->collectibles.sprite.endian);
	init_collectibles(s);
	init_base(s);
}
