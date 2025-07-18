/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:15:12 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/18 16:54:18 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_game(void *param)
{
	free(param);
	return(0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc > 3 || argc == 1)
		return (-1);
	game = malloc(sizeof(t_game));
	game->map.map = map_parser(argv);
	if (!is_valid(game->map.map) || (argc == 3 && !debug_mode(game, argv)))
		return (-1);
	game->mlx_ptr = mlx_init();
	init_game(game);
	mlx_hook(game->win.win_ptr, 17, 0, close_game, game);
	mlx_key_hook(game->win.win_ptr, keyloop, game);
	mlx_loop_hook(game->mlx_ptr, gameloop, game);
	mlx_loop(game->mlx_ptr);
}
