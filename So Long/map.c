/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:27:22 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/09 16:59:28 by pfreire-         ###   ########.fr       */
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

bool	is_first_line(char *map, int i)
{
	if ((map[i + 1] == '1' && map[i - 1] == '1') && i < is_top(map))
		return (true);
	return (false);
}

bool	should_put_wall(char *map, int i)
{
	if ((map[i - 1] == '\n' || map[i + 1] == '\n' || map[i + 1] == '\0'
			|| i == 0) || (map[i + 1] == '1' && map[i - 1] == '1'))
		return (true);
	return (false);
}

char	pick_wall(char *map, int i)
{
	if (is_first_line(map, i) && rng() % 7 == 1)
		return ('B');
	else if (is_first_line(map, i) && rng() % 3 == 0)
		return ('M');
	else if (should_put_wall(map, i))
		return ('W');
	else
		return ('X');
}

void	*which_sprite(t_game *s, int i)
{
	int h, w;
	if (s->map.map[i] == 'B')
		return (mlx_xpm_file_to_image(s->mlx_ptr, "assets/walls/Wall3.xpm", &w,
				&h));
	else if (s->map.map[i] == 'M')
		return (mlx_xpm_file_to_image(s->mlx_ptr, "assets/walls/Wall2.xpm", &w,
				&h));
	else if (s->map.map[i] == 'W')
		return (mlx_xpm_file_to_image(s->mlx_ptr, "assets/walls/Wall1.xpm", &w,
				&h));
	else if (s->map.map[i] == 'X')
		return (mlx_xpm_file_to_image(s->mlx_ptr, "assets/Box.xpm", &w, &h));
	else
		return (mlx_xpm_file_to_image(s->mlx_ptr, "assets/Ground.xpm", &w, &h));
}

char	pick_ground(char *map, int i)
{
	if (map[i] == '0')
		return ('0');
	return ('0');
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