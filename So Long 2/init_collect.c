/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:43:40 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/18 15:56:22 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	char_count(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
	if (c == '\0')
		return (1);
	return (count);
}

void	init_collectible(t_collect *s, int x, int y)
{
	s->coord.x = x * 128;
	s->coord.y = y * 128;
	s->active = true;
	s->coord.tile_x = x;
	s->coord.tile_y = y;
}

void	init_collectibles(t_game *s)
{
	int x;
	int y;
	int i;
	int k;

	s->collectibles.count = char_count(s->map.map, 'C');
	s->collectibles.collectible = malloc(sizeof(t_collect)
			* s->collectibles.count);
	if(!s->collectibles.collectible)
		exit(ft_printf("NO MEMORY, FREAKING OUT."));
	x = 0;
	y = 0;
	i = -1;
	k = 0;
	while (s->map.map[++i] != '\0')
	{
		if (s->map.map[i] == 'C')
		{
			init_collectible(&s->collectibles.collectible[k], x, y);
			k++;
		}
		x++;
		if (s->map.map[i] == '\n')
		{
			x = 0;
			y++;
		}
	}
}
