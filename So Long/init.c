/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:17:43 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/08 14:14:10 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_game *s, int spawnx, int spawny)
{
	s->player.sprite.img_ptr = mlx_xpm_file_to_image(s->win.mlx_ptr,
			"assets/Solid_Snake.xpm", &s->player.sprite.width,
			&s->player.sprite.height);
	s->player.sprite.img_addr = mlx_get_data_addr(s->player.sprite.img_ptr,
			&s->player.sprite.bits_per_pixel, &s->player.sprite.line_len,
			&s->player.sprite.endian);
	s->player.coord.x = spawnx;
	s->player.coord.y = spawny;
	render_player_buffer(s);
}

t_image	init_tile(t_game *s, int i)
{
	t_image	tile;

	tile.img_ptr = which_sprite(s, i);
	tile.img_addr = mlx_get_data_addr(tile.img_ptr, &tile.bits_per_pixel,
			&tile.line_len, &tile.endian);
	tile.width = 128;
	tile.height = 128;
	return (tile);
}

void	init_game(t_game *game)
{
	game->win.tilex = xtile(game->map.map);
	game->win.tiley = ytile(game->map.map);
	game->win.width = game->win.tilex * 128;
	game->win.height = game->win.tiley * 128;
	game->win.frame_buffer.img_ptr = mlx_new_image(game->win.mlx_ptr,
			game->win.width, game->win.height);
	game->win.frame_buffer.img_addr = mlx_get_data_addr(game->win.frame_buffer.img_ptr,
			&game->win.frame_buffer.bits_per_pixel,
			&game->win.frame_buffer.line_len, &game->win.frame_buffer.endian);
	game->win.frame_buffer.width = game->win.width;
	game->win.frame_buffer.height = game->win.height;
}
