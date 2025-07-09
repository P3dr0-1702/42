/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:13:57 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/09 17:53:16 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	spawn_point(t_game *s)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	i = 0;
	y = 0;
	while (s->map.map[i] != 'P')
	{
		x++;
		if (s->map.map[i] == '\n')
		{
			x = 0;
			y++;
		}
		i++;
	}
	s->player.coord.x = x * 128;
	s->player.coord.y = y * 128;
}

static int	gameloop(void *param)
{
	t_game	*game;

	game = param;
	render_frame(game);
	return (0);
}

static int	keyloop(void *param)
{
	t_game	*game;

	game = param;
	return (0);
}

static int	close_game(void *param)
{
	t_game	*game;

	game = param;
	ft_printf("Mission Aborted\n");
	mlx_destroy_image(game->mlx_ptr, game->base.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player.sprite.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->base.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->guards->sprite.img_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game *game;

	if (argc > 3 || argc == 1)
		return (-1);
	game = malloc(sizeof(t_game));
	game->map.map = map_parser(argv);
	if (!is_valid(game->map.map) && ft_strcmp(argv[2], "debug_mode=y") == 0)
		return (-1);
	game->mlx_ptr = mlx_init();
	init_game(game);
	if (ft_strcmp(argv[2], "debug_mode=y") == 0)
		print_game(game);
	spawn_point(game);
	mlx_hook(game->win.win_ptr, 17, 0, close_game, game);
	mlx_key_hook(game->mlx_ptr, keyloop, game);
	mlx_loop_hook(game->mlx_ptr, gameloop, game);
	mlx_loop(game->mlx_ptr);
}