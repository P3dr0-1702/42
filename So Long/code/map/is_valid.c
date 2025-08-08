/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:13:00 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/08 10:22:23 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool	no_forbidden_chars(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (!good_char(map[i]))
			return (false);
		i++;
	}
	return (true);
}

void	flood_fill(char **map, int *n, t_point point, bool *exit)
{
	t_point	p2;

	if (point.x < 0 || point.x >= my_strlen(map[0]) || point.y < 0
		|| point.y >= arr_len(map) || map[point.y][point.x] == 'F'
		|| map[point.y][point.x] == '1')
		return ;
	if (map[point.y][point.x] == 'C')
		(*n)++;
	if (map[point.y][point.x] == 'E')
		*exit = true;
	map[point.y][point.x] = 'F';
	p2 = point;
	p2.y++;
	flood_fill(map, n, p2, exit);
	p2.y -= 2;
	flood_fill(map, n, p2, exit);
	p2 = point;
	p2.x++;
	flood_fill(map, n, p2, exit);
	p2.x -= 2;
	flood_fill(map, n, p2, exit);
}

bool	pre_flood_fill(char *map)
{
	char	**temp;
	int		collectibles;
	int		count;
	t_point	p_coords;
	bool	exit;

	temp = ft_split(map, '\n');
	count = 0;
	p_coords = p_coord(temp);
	collectibles = char_count(map, 'C');
	flood_fill(temp, &count, p_coords, &exit);
	free_grid(temp);
	if (collectibles > count)
		return (false);
	return (true);
}

bool	no_consecutive_newline(char *s)
{
	int	i;

	if (s[0] == '\n')
		return (false);
	i = 1;
	while (s[i] != '\0')
	{
		if (s[i] == '\n' && s[i - 1] == '\n')
			return (false);
		i++;
	}
	return (true);
}

bool	is_valid(char *map)
{
	if (!no_forbidden_chars(map))
		return (ft_printf("Forbidden Chars\n"), false);
	if (!enough_objects(map))
		return (ft_printf("Missing Player, Exit or Collectibles\n"), false);
	if (!is_closed(map))
		return (ft_printf("Map is not closed\n"), false);
	if (!bounds(map))
		return (ft_printf("Map is too Big\n"), false);
	if (!no_consecutive_newline(map))
		return (ft_printf("Empty Line in file\n"), false);
	if (!pre_flood_fill(map))
		return (ft_printf("Map is Unwinable\n"), false);
	return (true);
}
