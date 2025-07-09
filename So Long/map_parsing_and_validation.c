/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_and_validation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:13:00 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/09 11:13:22 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_rectangle(char **map)
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

bool	one_word_one(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (str[0] == '1' && str[i - 1] == '1');
}

bool	only_ones(char *str)
{
	int	i;
	int size;

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

bool	is_closed(char *map)
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
	return (true && rectangular);
}

bool	at_least_one_collectible(char *map)
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

bool	only_one_player(char *map)
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

bool	only_one_exit(char *map)
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

bool	enough_objects(char *map)
{
	return (only_one_exit(map) && only_one_player(map)
		&& at_least_one_collectible(map));
}

bool	good_char(char c)
{
	if (c == 'P' || c == '0' || c == '1' || c == 'E' || c == 'C' || c == 'G'
		|| c == 'S' || c == '\n')
		return (true);
	return (false);
}

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

bool	is_valid(char *map)
{
	return (no_forbidden_chars(map) && enough_objects(map) && is_closed(map));
}


char	*map_parser(char **argv)
{
	int		fd;
	char	*temp;
	char	*line;
	char	*map;

	fd = open(argv[1], O_RDONLY);
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