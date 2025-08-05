/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_and_validation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:13:00 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/05 18:00:42 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_rectangle(char **map)
{
	size_t	i;
	int		j;

	i = ft_strlen(map[0]);
	j = 1;
	while (map[j] != NULL)
	{
		if (i != ft_strlen(map[j]))
			return (false);
		j++;
	}
	return (true);
}

static bool	one_word_one(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (str[0] == '1' && str[i - 1] == '1');
}

static bool	only_ones(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(str);
	while (i < size)
	{
		if (str[i] != '1' && str[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

static bool	is_closed(char *map)
{
	int		i;
	char	**maparr;
	bool	rectangular;

	i = 0;
	maparr = ft_split(map, '\n');
	if (!only_ones(maparr[0]))
		return (false);
	while (maparr[i] != NULL)
	{
		if (!(one_word_one(maparr[i])))
			return (false);
		i++;
	}
	if (!only_ones(maparr[i]))
		return (false);
	rectangular = is_rectangle(maparr);
	free_grid(maparr);
	return (true && rectangular);
}

static bool	at_least_one_collectible(char *map)
{
	int		i;
	bool	flag;

	i = 0;
	flag = false;
	while (map[i] != '\0')
	{
		if (map[i] == 'C')
			flag = true;
		i++;
	}
	return (flag);
}

static bool	only_one_player(char *map)
{
	int		i;
	bool	flag;

	i = 0;
	flag = false;
	while (map[i] != '\0')
	{
		if (map[i] == 'P')
		{
			if (flag)
				return (false);
			flag = true;
		}
		i++;
	}
	return (flag);
}

static bool	only_one_exit(char *map)
{
	int		i;
	bool	flag;

	i = 0;
	flag = false;
	while (map[i] != '\0')
	{
		if (map[i] == 'E')
		{
			if (flag)
				return (false);
			flag = true;
		}
		i++;
	}
	return (flag);
}

static bool	enough_objects(char *map)
{
	return (only_one_exit(map) && only_one_player(map)
		&& at_least_one_collectible(map));
}

static bool	good_char(char c)
{
	if (c == 'P' || c == '0' || c == '1' || c == 'E' || c == 'C' || c == 'G'
		|| c == '\n')
		return (true);
	return (false);
}

static bool	no_forbidden_chars(char *map)
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

t_point	p_coord(char **s)
{
	int		x;
	int		y;
	t_point	point;

	x = 0;
	y = 0;
	point.x = -1;
	point.y = -1;
	while (s[x])
	{
		y = 0;
		while (s[x][y])
		{
			if (s[x][y] == 'P')
			{
				point.x = x;
				point.y = y;
				return (point);
			}
			y++;
		}
		x++;
	}
	return (point);
}

int	arr_len(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{
		i++;
	}
	return (i);
}

int	my_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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
	bool exit;

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
		ft_printf("Forbidden Chars");
	if (!enough_objects(map))
		ft_printf("Missing Player, Exit or Collectibles");
	if (!is_closed(map))
		ft_printf("Map is not closed");
	if (!pre_flood_fill(map))
		ft_printf("Map is Unwinable");
	return (no_forbidden_chars(map) && enough_objects(map) && is_closed(map)
		&& pre_flood_fill(map));
}

static bool	is_ber(char *str)
{
	int		i;
	char	*ber;
	int		k;

	ber = "ber";
	i = 0;
	while (str[i] != '.')
		i++;
	i++;
	k = 0;
	while (str[i + k] != '\0')
	{
		if (str[i + k] != ber[k])
			return (false);
		k++;
	}
	return (true);
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
	while ((line = get_next_line(fd)) != NULL)
	{
		temp = ft_strjoin(map, line);
		free(map);
		map = temp;
		free(line);
	}
	close(fd);
	return (map);
}
