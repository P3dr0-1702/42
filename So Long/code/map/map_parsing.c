/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:13:00 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/06 17:28:19 by pfreire-         ###   ########.fr       */
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

bool	is_valid(char *map)
{
	if (!no_forbidden_chars(map))
		ft_printf("Forbidden Chars\n");
	if (!enough_objects(map))
		ft_printf("Missing Player, Exit or Collectibles\n");
	if (!is_closed(map))
		ft_printf("Map is not closed\n");
	if (!pre_flood_fill(map))
		ft_printf("Map is Unwinable\n");
	if (!bounds(map))
		ft_printf("Map is too Big\n");
	return (no_forbidden_chars(map) && enough_objects(map) && is_closed(map)
		&& pre_flood_fill(map) && bounds(map));
}

char	*map_parser(char **argv)
{
	int		fd;
	char	*temp;
	char	*line;
	char	*map;

	fd = open(argv[1], O_RDONLY);
	if (!debug_mode(NULL, argv) && !is_ber(argv[1]))
	{
		printf("shouldnt happen");
		exit(EXIT_FAILURE);
	}
	if (fd < 0)
		return (NULL);
	map = ft_strdup("");
	line = get_next_line(fd);
	while ((line) != NULL)
	{
		temp = ft_strjoin(map, line);
		free(map);
		map = temp;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
