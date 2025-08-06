/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:26:05 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/06 17:27:32 by pfreire-         ###   ########.fr       */
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
