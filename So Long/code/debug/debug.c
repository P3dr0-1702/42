/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:15:44 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/07 13:37:23 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

char	*y_or_n(bool a)
{
	if (a)
		return ("Yes");
	return ("No");
}

void	print_collectible(t_collect *c)
{
	print_point(&c->coord);
	if (c->active)
		ft_printf("Status: Active\n");
	else
		ft_printf("Status: Deactive\n");
}

int	print_collectibles(t_game *s)
{
	int	i;

	i = 0;
	if (s->collectibles.count == 0)
		return (ft_printf("No Colletibles to Show \
							(Debug Mode Should be On(is ON ?: % s))\n ",
				y_or_n(s->debug_mode)));
	ft_printf("┌───Displaying %d Rations────┐\n", s->collectibles.count);
	while (i < s->collectibles.count)
	{
		ft_printf("┌───Ration #%d──┐\n", i);
		print_collectible(&s->collectibles.collectible[i]);
		ft_printf("└───────────────┘\n");
		i++;
	}
	ft_printf("└────────────────────────────┘\n");
	return (0);
}

void	print_game(t_game *s)
{
	ft_printf("\n=============================== GAME \
STATE ================================\n");
	ft_printf("MLX Context Pointer: %p\n", s->mlx_ptr);
	ft_printf("┌─────────────────────── Game Base ────────────────────────┐\n");
	print_image(&s->base);
	ft_printf("└──────────────────────────────────────────────────────────┘\n");
	print_window(&s->win);
	print_map(&s->map);
	print_player(&s->player);
	print_collectibles(s);
	ft_printf("=============================== END O\
F DUMP ===============================\n");
}

bool	debug_mode(t_game *s, char **argv)
{
	if (argv[2])
	{
		if (ft_strcmp(argv[2], "debug_mode=y") == 0)
		{
			if (s)
				s->debug_mode = true;
			return (true);
		}
	}
	if (s)
		s->debug_mode = false;
	return (false);
}
