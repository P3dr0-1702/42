/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_picker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:24:22 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/08 11:27:03 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	pick_wall(char *map, int i)
{
	if (is_first_line(map, i) && random_number() % 7 == 1)
		return ('B');
	else if (is_first_line(map, i) && random_number() % 3 == 0)
		return ('M');
	else if (should_put_wall(map, i))
		return ('W');
	else
		return ('X');
}

bool	should_put_wall(char *map, int i)
{
	if ((map[i - 1] == '\n' || map[i + 1] == '\n' || map[i + 1] == '\0'
			|| i == 0) || (map[i + 1] == '1' && map[i - 1] == '1'))
		return (true);
	return (false);
}

bool	is_first_line(char *map, int i)
{
	if ((map[i - 1] != '\0' && map[i + 1] != '\n') && map[i - 1] != '\n'
		&& i < firstline(map))
		return (true);
	return (false);
}

void	*which_sprite(t_game *s, int i)
{
	if (s->map.map[i] == 'B')
		return (mlx_xpm_file_to_image(s->win.mlx_ptr, "assets/walls/Wall3.xpm",
				&s->win.width, &s->win.height));
	else if (s->map.map[i] == 'M')
		return (mlx_xpm_file_to_image(s->win.mlx_ptr, "assets/walls/Wall2.xpm",
				&s->win.width, &s->win.height));
	else if (s->map.map[i] == 'W')
		return (mlx_xpm_file_to_image(s->win.mlx_ptr, "assets/walls/Wall1.xpm",
				&s->win.width, &s->win.height));
	else if (s->map.map[i] == 'X')
		return (mlx_xpm_file_to_image(s->win.mlx_ptr, "assets/Box.xpm",
				&s->win.width, &s->win.height));
	else
		return (mlx_xpm_file_to_image(s->win.mlx_ptr, "assets/Ground.xpm",
				&s->win.width, &s->win.height));
}
