/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:26:05 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/11 09:55:25 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

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

bool	is_ber(char *str)
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
		printf("Wrong file extension");
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
