/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:15:12 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/17 17:30:23 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_game *game;
	if(argc > 3 || argc ==1)
		return(-1);
	game = malloc(sizeof(t_game));
	game->map.map = map_parser(argv);
	if (!is_valid(game->map.map) || (argc == 3 && !debug_mode(argv)))
		return -1;
	game->mlx_ptr = mlx_init();
}
