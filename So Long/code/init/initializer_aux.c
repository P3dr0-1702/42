/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:07:10 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/15 12:31:59 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

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

void	init_map(t_game *s)
{
	s->map.grid = NULL;
	s->map.grid = ft_split(s->map.map, '\n');
	if (!s->map.grid)
		ft_printf("Could not store map matrix\n");
	s->map.map = store_map(s->map.map);
	if (!s->map.map || !s->map.grid)
	{
		ft_printf("Report: No Memory, download more RAM\n");
		close_game(s);
	}
}
