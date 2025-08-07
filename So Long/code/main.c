/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:15:12 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/07 10:28:02 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_grid(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	close_game(t_game *param)
{
	ft_printf("CLOSING GAME\n");
	mlx_destroy_image(param->mlx_ptr, param->collectibles.sprite.img_ptr);
	mlx_destroy_image(param->mlx_ptr, param->player.sprite.img_ptr);
	mlx_destroy_image(param->mlx_ptr, param->base.img_ptr);
	mlx_destroy_image(param->mlx_ptr, param->win.frame_buffer.img_ptr);
	mlx_destroy_window(param->mlx_ptr, param->win.win_ptr);
	mlx_destroy_display(param->mlx_ptr);
	free_grid(param->map.grid);
	free(param->collectibles.collectible);
	free(param->map.map);
	return (0);
}

int	invalid_map(t_game *s)
{
	free(s->map.map);
	free(s);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if ((argc > 3 || argc == 1) || ((argc == 3) && ft_strcmp(argv[2],
				"debug_mode=y") != 0))
		return (ft_printf("Wrong args\n"));
	game = malloc(sizeof(t_game));
	if (!game)
		exit(EXIT_FAILURE);
	game->map.map = map_parser(argv);
	if ((!is_valid(game->map.map) && !debug_mode(game, argv)) || (argc == 3
			&& !debug_mode(game, argv)))
		return (invalid_map(game));
	game->mlx_ptr = mlx_init();
	init_game(game);
	mlx_hook(game->win.win_ptr, 17, 0, close_game, game);
	mlx_key_hook(game->win.win_ptr, keyloop, game);
	mlx_loop_hook(game->mlx_ptr, gameloop, game);
	mlx_loop(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
	return (0);
}
