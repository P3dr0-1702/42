/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:30:00 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/17 17:16:11 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyloop(int key, t_game *game)
{
	int	x;
	int	y;

	if (key == KEY_R && game->debug_mode)
		print_game(game);
	else if (key == KEY_A || key == KEY_LEFT)
		move(game, MOVE_LEFT);
	else if (key == KEY_W || key == KEY_UP)
		move(game, MOVE_UP);
	else if (key == KEY_D || key == KEY_LEFT)
		move(game, MOVE_LEFT);
	else if (key == KEY_S || key == KEY_DOWN)
		move(game, MOVE_DOWN);
}

int	gameloop(void *param)
{
	t_game *game;
	game = param;
	mlx_key_hook(game->win.win_ptr, keyloop, game);
	render_frame(game);
	usleep(16667);
}