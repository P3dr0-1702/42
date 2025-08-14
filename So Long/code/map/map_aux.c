/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:35:08 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/14 10:21:30 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	is_top(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		i++;
	return (i);
}

int	is_bottom(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
		i++;
	i -= 2;
	while (map[i] != '\n')
		i--;
	return (i);
}

bool	is_first_line(char *map, int i)
{
	if (i == my_strlen(map))
		return (false);
	if (i == 0)
	{
		if ((map[i + 1] == '1') && i < is_top(map))
			return (true);
	}
	if ((map[i + 1] == '1' && map[i - 1] == '1') && i < is_top(map))
		return (true);
	return (false);
}

void	*which_ground(t_game *s, int i)
{
	int	h;
	int	w;

	if (s->map.map[i] == GROUND2)
		return (mlx_xpm_file_to_image(s->mlx_ptr, GROUND_PATH "Ground2.xpm", &w,
				&h));
	else if (s->map.map[i] == GROUND3)
		return (mlx_xpm_file_to_image(s->mlx_ptr, GROUND_PATH "Ground3.xpm", &w,
				&h));
	else if (s->map.map[i] == GROUND4)
		return (mlx_xpm_file_to_image(s->mlx_ptr, GROUND_PATH "Ground4.xpm", &w,
				&h));
	else if (s->map.map[i] == DESTROYED_GROUND)
		return (mlx_xpm_file_to_image(s->mlx_ptr,
				OBSTACLES_PATH "Destroyed_Ground.xpm", &w, &h));
	else if (s->map.map[i] == OCTUPUSS)
		return (mlx_xpm_file_to_image(s->mlx_ptr, OBSTACLES_PATH "Octopuss.xpm",
				&w, &h));
	else if (s->map.map[i] == BOX)
		return (mlx_xpm_file_to_image(s->mlx_ptr, OBSTACLES_PATH "Box.xpm", &w,
				&h));
	else
		return (mlx_xpm_file_to_image(s->mlx_ptr, GROUND_PATH "Ground.xpm", &w,
				&h));
}

void	*which_sprite(t_game *s, int i)
{
	int	h;
	int	w;

	if (s->debug_mode)
		return (debug_limits(s, i));
	if (s->map.map[i] == KOJIMA_WALL)
		return (mlx_xpm_file_to_image(s->mlx_ptr,
				WALL_PATH "Absolute_Gameplay.xpm", &w, &h));
	else if (s->map.map[i] == WALL_SIGN)
		return (mlx_xpm_file_to_image(s->mlx_ptr, WALL_PATH "Wall4.xpm", &w,
				&h));
	else if (s->map.map[i] == WALL_POSTER)
		return (mlx_xpm_file_to_image(s->mlx_ptr, WALL_PATH "Wall3.xpm", &w,
				&h));
	else if (s->map.map[i] == WALL_PANEL)
		return (mlx_xpm_file_to_image(s->mlx_ptr, WALL_PATH "Wall2.xpm", &w,
				&h));
	else if (s->map.map[i] == WALL)
		return (mlx_xpm_file_to_image(s->mlx_ptr, WALL_PATH "Wall1.xpm", &w,
				&h));
	else if (s->map.map[i] == 'E')
		return (mlx_xpm_file_to_image(s->mlx_ptr, ASSETS_PATH "Helipad.xpm", &w,
				&h));
	return (which_ground(s, i));
}
