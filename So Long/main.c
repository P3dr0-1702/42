/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:39:10 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/08 16:45:06 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*store_base(char *map)
{
	int		i;
	int		x;
	int		y;
	char	*str;

	i = 0;
	x = 0;
	y = 0;
	str = malloc(sizeof(char) * ft_strlen(map));
	while (map[i] != '\0')
	{
		if (map[i] == '1')
			str[i] = pick_wall(map, i);
		else
			str[i] = map[i];
		i++;
	}
	return (str);
}

char	*make_window(t_game *s)
{
	s->win.width = 128 * xtile(s->map.map);
	s->win.height = 128 * ytile(s->map.map);
	s->win.win_ptr = mlx_new_window(s->win.mlx_ptr, s->win.width, s->win.height,
			"TAE: Metal Gear");
	s->map.map = store_base(s->map.map);
	return (s->map.map);
}

int handle_exit(void *param)
{
	(void)param;
	printf("exit\n");
	exit(0);
	return (0);
}

int keycode(int keycode, t_game *game)
{
	game->alert_cooldown = 1;
	keycode = 0;
	printf("hello");
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	int		i;
	int		x;
	int		y;

	game = malloc(sizeof(t_game));
	if (argc != 2)
		return (-1);
	game->map.map = map_parser(argv);
	if (!is_valid(game->map.map))
		printf("Error\n");
	game->win.mlx_ptr = mlx_init();
	game->map.map = make_window(game);
	printf("%s\n", game->map.map);
	init_game(game);
	init_player(game, 0, 0);
	i = 0;
	x = 0;
	y = 0;
	mlx_hook(game->win.win_ptr, 17, 0, handle_exit, &game);
	mlx_key_hook(game->win.win_ptr, keycode, game);
	mlx_loop(game->win.mlx_ptr);
	printf("done");
	sleep(500);
	free(game);
}
