/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:09:25 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/14 10:31:26 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// void	*debug_limits(t_game *s, int i)
// {
// 	int h;
// 	int w;

// 	if(s->map.map[i] == )
// 	if (s->map.map[i] == GROUND2)
// 		return (mlx_xpm_file_to_image(s->mlx_ptr,
// 				ASSETS_PATH "debug/Limit_Square.xpm", &w, &h));
// 	else if (s->map.map[i] == GROUND3)
// 		return (mlx_xpm_file_to_image(s->mlx_ptr,
// 				ASSETS_PATH "debug/Limit_Square.xpm", &w, &h));
// 	else if (s->map.map[i] == GROUND4)
// 		return (mlx_xpm_file_to_image(s->mlx_ptr,
// 				ASSETS_PATH "debug/Limit_Square.xpm", &w, &h));
// 	else if (s->map.map[i] == OCTUPUSS)
// 		return (mlx_xpm_file_to_image(s->mlx_ptr,
// 				ASSETS_PATH "debug/Debug_Box.xpm", &w, &h));
// 	else if (s->map.map[i] == BOX)
// 		return (mlx_xpm_file_to_image(s->mlx_ptr,
// 				ASSETS_PATH "debug/Debug_Box.xpm", &w, &h));
// 	else
// 		return (mlx_xpm_file_to_image(s->mlx_ptr,
// 				ASSETS_PATH "debug/Limit_Square.xpm", &w, &h));
// }

void	*which_debug_ground(t_game *s, int i)
{
	int	h;
	int	w;

	if (s->map.map[i] == GROUND2)
		return (mlx_xpm_file_to_image(s->mlx_ptr,
				ASSETS_PATH "debug/Debug_Ground.xpm", &w, &h));
	else if (s->map.map[i] == GROUND3)
		return (mlx_xpm_file_to_image(s->mlx_ptr,
				ASSETS_PATH "debug/Debug_Ground.xpm", &w, &h));
	else if (s->map.map[i] == GROUND4)
		return (mlx_xpm_file_to_image(s->mlx_ptr,
				ASSETS_PATH "debug/Debug_Ground.xpm", &w, &h));
	else if (s->map.map[i] == DESTROYED_GROUND)
		return (mlx_xpm_file_to_image(s->mlx_ptr,
				ASSETS_PATH "debug/Debug_Box.xpm", &w, &h));
	else if (s->map.map[i] == OCTUPUSS)
		return (mlx_xpm_file_to_image(s->mlx_ptr,
				ASSETS_PATH "debug/Debug_Box.xpm", &w, &h));
	else if (s->map.map[i] == BOX)
		return (mlx_xpm_file_to_image(s->mlx_ptr,
				ASSETS_PATH "debug/Debug_Box.xpm", &w, &h));
	else
		return (mlx_xpm_file_to_image(s->mlx_ptr,
				ASSETS_PATH "debug/Debug_Ground.xpm", &w, &h));
}

void	*debug_limits(t_game *s, int i)
{
	int	h;
	int	w;

	if (s->map.map[i] == KOJIMA_WALL)
		return (mlx_xpm_file_to_image(s->mlx_ptr,
				ASSETS_PATH "debug/Debug_Wall.xpm", &w, &h));
	else if (s->map.map[i] == WALL_SIGN)
		return (mlx_xpm_file_to_image(s->mlx_ptr,
				ASSETS_PATH "debug/Debug_Wall.xpm", &w, &h));
	else if (s->map.map[i] == WALL_POSTER)
		return (mlx_xpm_file_to_image(s->mlx_ptr,
				ASSETS_PATH "debug/Debug_Wall.xpm", &w, &h));
	else if (s->map.map[i] == WALL_PANEL)
		return (mlx_xpm_file_to_image(s->mlx_ptr,
				ASSETS_PATH "debug/Debug_Wall.xpm", &w, &h));
	else if (s->map.map[i] == WALL)
		return (mlx_xpm_file_to_image(s->mlx_ptr,
				ASSETS_PATH "debug/Debug_Wall.xpm", &w, &h));
	else if (s->map.map[i] == 'E')
		return (mlx_xpm_file_to_image(s->mlx_ptr,
				ASSETS_PATH "debug/Debug_Exit.xpm", &w, &h));
	return (which_debug_ground(s, i));
}
