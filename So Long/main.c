/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:15:12 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/05 18:12:43 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
}


void free_collectibles(t_game *s)
{
	int i = 0;
	while(i < s->collectibles.count)
	{
		free(&s->collectibles.collectible[i]);
		i++;
	}
}

int	close_game(t_game *param)
{
	mlx_destroy_image(param->mlx_ptr, param->collectibles.sprite.img_ptr);
	// free(param->collectibles.sprite.img_addr);
	mlx_destroy_image(param->mlx_ptr, param->player.sprite.img_ptr);
	// free(param->player.sprite.img_addr);
	mlx_destroy_image(param->mlx_ptr, param->base.img_ptr);
	// free(param->base.img_addr);
	mlx_destroy_image(param->mlx_ptr, param->win.frame_buffer.img_ptr);
	mlx_destroy_window(param->mlx_ptr, param->win.win_ptr);
	mlx_destroy_display(param->mlx_ptr);
	free_grid(param->map.grid);
	free_collectibles(param);
	free(param->map.map);
	free(param->mlx_ptr);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc > 3 || argc == 1)
		return (-1);
	game = malloc(sizeof(t_game));
	if (!game)
		exit(EXIT_FAILURE);
	game->map.map = map_parser(argv);
	if ((!is_valid(game->map.map) && !debug_mode(game, argv)) || (argc == 3
			&& !debug_mode(game, argv)))
		return (-1);
	game->mlx_ptr = mlx_init();
	init_game(game);
	mlx_hook(game->win.win_ptr, 17, 0, close_game, game);
	mlx_key_hook(game->win.win_ptr, keyloop, game);
	mlx_loop_hook(game->mlx_ptr, gameloop, game);
	mlx_loop(game->mlx_ptr);
}
