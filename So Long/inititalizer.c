/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inititalizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:40:03 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/05 18:03:25 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	spawn_point(t_game *s)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	i = 0;
	y = 0;
	while (s->map.map[i] != '\0')
	{
		if (s->map.map[i] == 'P')
			break ;
		x++;
		if (s->map.map[i] == '\n')
		{
			x = 0;
			y++;
		}
		i++;
	}
	s->player.coord.tile_x = x;
	s->player.coord.tile_y = y;
	s->player.coord.x = (x * 128) + 32;
	s->player.coord.y = (y * 128) + 7;
}

void	init_player_imgptr(t_game *s)
{
	s->player.sprite.img_ptr = mlx_xpm_file_to_image(s->mlx_ptr,
			ENT_PATH "Boxed_SS1.xpm", &s->player.sprite.width,
			&s->player.sprite.heigth);
}

void	init_player_imgaddr(t_game *s)
{
	s->player.sprite.img_addr = mlx_get_data_addr(s->player.sprite.img_ptr,
			&s->player.sprite.bpp, &s->player.sprite.l_len,
			&s->player.sprite.endian);
}

void	init_player(t_game *s)
{
	spawn_point(s);
	init_player_imgptr(s);
	if (!s->player.sprite.img_ptr)
		exit(EXIT_FAILURE);
	init_player_imgaddr(s);
	s->player.collectibles = 0;
	s->player.moves = 0;
}

void	init_window(t_game *s)
{
	s->win.ntilesx = xtile(s->map.map);
	s->win.ntilesy = ytile(s->map.map);
	s->win.width = 128 * xtile(s->map.map);
	s->win.height = 128 * ytile(s->map.map);
	s->win.win_ptr = mlx_new_window(s->mlx_ptr, s->win.width, s->win.height,
			"TAE: Metal Gear");
	s->win.frame_buffer.img_ptr = mlx_new_image(s->mlx_ptr, s->win.width,
			s->win.height);
	s->win.frame_buffer.img_addr = mlx_get_data_addr(s->win.frame_buffer.img_ptr,
			&s->win.frame_buffer.bpp, &s->win.frame_buffer.l_len,
			&s->win.frame_buffer.endian);
	s->win.frame_buffer.width = s->win.width;
	s->win.frame_buffer.heigth = s->win.height;
}

void	init_map(t_game *s)
{
	s->map.grid = ft_split(s->map.map, '\n');
	s->map.map = store_map(s->map.map);
}

void	init_game(t_game *s)
{
	init_map(s);
	init_window(s);
	s->base.img_ptr = mlx_new_image(s->mlx_ptr, s->win.width, s->win.height);
	s->base.img_addr = mlx_get_data_addr(s->base.img_ptr, &s->base.bpp,
			&s->base.l_len, &s->base.endian);
	s->base.width = s->win.width;
	s->base.heigth = s->win.height;
	init_base(s);
	init_collectibles(s);
	s->collectibles.sprite.img_ptr = mlx_xpm_file_to_image(s->mlx_ptr,
			ASSETS_PATH "Ration.xpm", &s->collectibles.sprite.width,
			&s->collectibles.sprite.heigth);
	s->collectibles.sprite.img_addr = mlx_get_data_addr(s->collectibles.sprite.img_ptr,
			&s->collectibles.sprite.bpp, &s->collectibles.sprite.l_len,
			&s->collectibles.sprite.endian);
	init_player(s);
}
