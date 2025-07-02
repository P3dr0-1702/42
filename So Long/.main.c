/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:45:01 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/02 17:34:54 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/time.h>

int	main(void)
{
	t_window	*s;
	int			i;
	int			y;

	s = malloc(sizeof(t_window));
	s->mlx_ptr = mlx_init();
	s->width = 64;
	s->height = 64;
	if (!s->mlx_ptr)
		return (1);
	s->win_ptr = mlx_new_window(s->mlx_ptr, 1280, 960,
			"Tatical Espionage Action: Metal Gear Solid");
	s->img_ptr = mlx_xpm_file_to_image(s->mlx_ptr, "assets/Ground.xpm",
			&s->height, &s->width);
	i = 0;
	y = 0;
	while (i <= 1280)
	{
		y = 0;
		while (y <= 896)
		{
			mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, i, y);
			y += 126;
		}
		i += 126;
	}
	i = 0;
	s->img_ptr = mlx_xpm_file_to_image(s->mlx_ptr, "assets/Solid_Snake.xpm",
			&s->height, &s->width);
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, 0, 0);
	s->img_ptr = mlx_xpm_file_to_image(s->mlx_ptr, "assets/Boxed_SS1.xpm",
			&s->height, &s->width);
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, 0, 64);
	mlx_loop(s->mlx_ptr);
	free(s);
}
