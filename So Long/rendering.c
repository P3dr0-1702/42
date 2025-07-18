/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:55:21 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/14 17:45:59 by pfreire-         ###   ########.fr       */
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
			{
				ft_pixel_put(&s->win.frame_buffer, x, y, color);
			}
			x++;
		}
		y++;
	}
}

void	render_collectible_into_buffer(t_game *g, t_collect *c)
{
	t_point			point;
	unsigned int	color;

	point.y = 0;
	color = 0;
	if (!c->active)
		return ;
	while (point.y < g->collectibles.sprite.heigth)
	{
		point.x = 0;
		while (point.x < g->collectibles.sprite.width)
		{
			color = pixel_get(&g->collectibles.sprite, point.x, point.y);
			if ((color >> 24) != 0xFF)
			{
				ft_pixel_put(&g->win.frame_buffer, c->coord.x + point.x,
					c->coord.y + point.y, color);
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

void	render_player_into_buffer(t_game *s)
{
	t_point			point;
	unsigned int	color;

	point.y = 0;
	color = 0;
	while (point.y < s->player.sprite.heigth)
	{
		point.x = 0;
		while (point.x < s->player.sprite.width)
		{
			color = pixel_get(&s->player.sprite, point.x, point.y);
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

void	clear_frame(t_game *s)
{
	size_t	bytes;

	bytes = (size_t)s->win.frame_buffer.l_len * s->win.frame_buffer.heigth;
	ft_bzero(s->win.frame_buffer.img_addr, bytes);
}

void	render_base_into_fb(t_game *s)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < s->win.frame_buffer.heigth)
	{
		x = 0;
		while (x < s->win.frame_buffer.width)
		{
			color = pixel_get(&s->base, x, y);
			ft_pixel_put(&s->win.frame_buffer, x, y, color);
			x++;
		}
		y++;
	}
}

void	render_frame(t_game *s)
{
	clear_frame(s);

	render_base_into_buffer(s);
	render_collectibles_into_buffer(s);
	render_player_into_buffer(s);
	mlx_put_image_to_window(s->mlx_ptr, s->win.win_ptr,
		s->win.frame_buffer.img_ptr, 0, 0);
}