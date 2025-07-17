/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inititalizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:40:03 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/17 18:09:28 by pfreire-         ###   ########.fr       */
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
	s->player.sprite[0][0].img_ptr = mlx_xpm_file_to_image(s->mlx_ptr,
			ENT_PATH "Boxed_SS1.xpm", &s->player.sprite[0][0].width,
			&s->player.sprite[0][0].heigth);
	s->player.sprite[0][1].img_ptr = mlx_xpm_file_to_image(s->mlx_ptr,
			ENT_PATH "Boxed_SS2.xpm", &s->player.sprite[0][1].width,
			&s->player.sprite[0][1].heigth);
	s->player.sprite[1][0].img_ptr = mlx_xpm_file_to_image(s->mlx_ptr,
			ENT_PATH "SS_Frame1.xpm", &s->player.sprite[1][0].width,
			&s->player.sprite[1][0].heigth);
	s->player.sprite[1][1].img_ptr = mlx_xpm_file_to_image(s->mlx_ptr,
			ENT_PATH "SS_Frame2.xpm", &s->player.sprite[1][1].width,
			&s->player.sprite[1][1].heigth);
}

void	init_player_imgaddr(t_game *s)
{
	s->player.sprite[0][0].img_addr = mlx_get_data_addr(s->player.sprite[0][0].img_ptr,
			&s->player.sprite[0][0].bpp, &s->player.sprite[0][0].l_len,
			&s->player.sprite[0][0].endian);
	s->player.sprite[0][1].img_addr = mlx_get_data_addr(s->player.sprite[0][1].img_ptr,
			&s->player.sprite[0][1].bpp, &s->player.sprite[0][1].l_len,
			&s->player.sprite[0][1].endian);
	s->player.sprite[1][0].img_addr = mlx_get_data_addr(s->player.sprite[1][0].img_ptr,
			&s->player.sprite[1][0].bpp, &s->player.sprite[1][0].l_len,
			&s->player.sprite[1][0].endian);
	s->player.sprite[1][1].img_addr = mlx_get_data_addr(s->player.sprite[1][1].img_ptr,
			&s->player.sprite[1][1].bpp, &s->player.sprite[1][1].l_len,
			&s->player.sprite[1][1].endian);
}

void	init_player(t_game *s)
{
	spawn_point(s);
	init_player_imgptr(s);
	if (!s->player.sprite[0][0].img_ptr || !s->player.sprite[0][1].img_ptr
		|| !s->player.sprite[1][0].img_ptr || !s->player.sprite[1][1].img_ptr)
		exit;
	init_player_imgaddr(s);
	??
	//continue here
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

void	init_tile_base(t_game *s, int i)
{
}

void	init_game(t_game *s)
{
	init_window(s);
}