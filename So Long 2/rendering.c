/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:04:09 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/18 16:42:15 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_base_into_buffer(t_game *s)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < s->base.heigth)
	{
		x = 0;
		while (x < s->base.width)
		{
			color = pixel_get(&s->base, x, y);
			if ((color >> 24) != 0xFF)
				ft_pixel_put(&s->win.frame_buffer, x, y, color);
			x++;
		}
		y++;
	}
}

void	render_collectible_into_buffer(t_game *s, t_collect *c)
{
	t_point			point;
	unsigned int	color;

	point.y = 0;
	color = 0;
	if (!c->active)
		return ;
	while (point.y < s->collectibles.sprite.heigth)
	{
		point.x = 0;
		while (point.x < s->collectibles.sprite.width)
		{
			color = pixel_get(&s->collectibles.sprite, point.x, point.y);
			if ((color >> 24) != 0xFF)
			{
				ft_pixel_put(&s->win.frame_buffer, c->coord.x + point.x,
					c->coord.y + point.y, color);
			}
			point.x++;
		}
		point.y++;
	}
}

void	render_player_into_buffer(t_game *s)
{
	t_point			point;
	unsigned int	color;

	point.y = 0;
	while (point.y < s->player.sprite[s->player.state][s->player.frame].heigth)
	{
		point.x = 0;
		while (point.x < s->player.sprite[s->player.state][s->player.frame].width)
		{
			color = pixel_get(&s->player.sprite[s->player.state][s->player.frame],
					point.x, point.y);
			if ((color >> 24) != 0xFF)
			{
				ft_pixel_put(&s->win.frame_buffer, s->player.coord.x + point.x,
					s->player.coord.y + point.y, color);
			}
			point.x++;
		}
		point.y++;
	}
}

void	render_collectibles_into_buffer(t_game *s)
{
	int	i;

	i = 0;
	while (i < s->collectibles.count)
	{
		render_collectible_into_buffer(s, &s->collectibles.collectible[i]);
		i++;
	}
}

void	clear_frame(t_game *s)
{
	size_t	bytes;

	bytes = (size_t)(s->win.frame_buffer.l_len * s->win.frame_buffer.heigth);
	ft_bzero(s->win.frame_buffer.img_addr, bytes);
}

void	render_frame(t_game *s)
{
	clear_frame(s);

	render_base_into_buffer(s);
	render_collectibles_into_buffer(s);
	s->player.state = 0;
	s->player.frame = 0;
	render_player_into_buffer(s);
	//	render_enemy_into_buffer(s);
	mlx_put_image_to_window(s->mlx_ptr, s->win.win_ptr,
		s->win.frame_buffer.img_ptr, 0, 0);
}