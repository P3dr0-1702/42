/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:27:22 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/18 16:04:56 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if ((map[i + 1] == '1' && map[i - 1] == '1') && i < is_top(map))
		return (true);
	return (false);
}

bool	should_put_wall(char *map, int i)
{
	if ((map[i - 1] == '\n' || map[i + 1] == '\n' || map[i + 1] == '\0'
			|| i == 0) || ((map[i + 1] == '1' && map[i - 1] == '1')
			&& (i < is_top(map) || i > is_bottom(map))))
		return (true);
	return (false);
}

char	pick_obstacle(void)
{
	int	temp_rn;

	temp_rn = rng() % 10;
	if (temp_rn == 1)
		return (OCTUPUSS);
	else if (temp_rn > 5)
		return (DESTROYED_GROUND);
	else
		return (BOX);
}

char	pick_wall(char *map, int i)
{
	if (is_first_line(map, i) && rng() % 7 == 1)
		return (WALL_POSTER);
	else if (is_first_line(map, i) && rng() % 3 == 0)
		return (WALL_PANEL);
	else if (should_put_wall(map, i) && rng() % 100 == 5)
		return (KOJIMA_WALL);
	else if (should_put_wall(map, i) && rng() % 3 == 1)
		return (WALL_SIGN);
	else if (should_put_wall(map, i))
		return (WALL);
	else
		return (pick_obstacle());
}

char	pick_ground(char *map, int i)
{
	int	temp_rn;

	if (map[i] != '0')
		return (0);
	if (rng() % 100 == 1)
		return (GROUND2);
	else if (rng() % 100 < 66)
	{
		temp_rn = rng() % 3;
		if ((temp_rn == 0) && (rng() % 3 == 0))
			return (GROUND4);
		else if (temp_rn == 1)
			return (GROUND3);
	}
	return (GROUND1);
}

void	*which_ground(t_game *s, int i)
{
	int h, w;
	if (s->map.map[i] == GROUND2)
		return (mlx_xpm_file_to_image(s->mlx_ptr, GROUND_PATH "Ground2.xpm", &w,
				&h));
	else if (s->map.map[i] == GROUND3)
		return (mlx_xpm_file_to_image(s->mlx_ptr, GROUND_PATH "Ground3.xpm", &w,
				&h));
	else if (s->map.map[i] == GROUND4)
		return (mlx_xpm_file_to_image(s->mlx_ptr, GROUND_PATH "Ground4.xpm", &w,
				&h));
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
	int h, w;
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
	else if (s->map.map[i] == DESTROYED_GROUND)
		return (mlx_xpm_file_to_image(s->mlx_ptr,
				OBSTACLES_PATH "Destroyed_Ground.xpm", &w, &h));
	else
		return (which_ground(s, i));
}

char	*store_map(char *map)
{
	int i;
	int x;
	int y;
	char *str;
	i = 0;
	x = 0;
	y = 0;
	str = malloc(sizeof(char) * (ft_strlen(map) + 1));
	while (map[i] != '\0')
	{
		if (map[i] == '1')
			str[i] = pick_wall(map, i);
		else if (map[i] == '0')
			str[i] = pick_ground(map, i);
		else
			str[i] = map[i];
		i++;
	}
	str[i] = '\0';
	free(map);
	return (str);
}