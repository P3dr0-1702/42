/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:22:07 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/07 11:23:36 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

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

bool	bounds(char *map)
{
	if (xtile(map) > 12 || ytile(map) > 8)
		return (false);
	return (true);
}

int	my_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

bool	enough_objects(char *map)
{
	return (only_one_exit(map) && only_one_player(map)
		&& at_least_one_collectible(map));
}

bool	good_char(char c)
{
	if (c == 'P' || c == '0' || c == '1' || c == 'E' || c == 'C' || c == '\n')
		return (true);
	return (false);
}
