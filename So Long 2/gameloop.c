/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:30:00 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/18 17:15:32 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyloop(int key, t_game *game)
{
	if (key == KEY_R && game->debug_mode)
		print_game(game);
	else if (key == KEY_A || key == KEY_LEFT)
		move_left(game);
	else if (key == KEY_W || key == KEY_UP)
		move_up(game);
	else if (key == KEY_D || key == KEY_LEFT)
		move_right(game);
	else if (key == KEY_S || key == KEY_DOWN)
		move_down(game);
	return (0);
}

int	gameloop(void *param)
{
	t_game *game;
	game = param;
	mlx_key_hook(game->win.win_ptr, keyloop, game);
	render_frame(game);
	if(game_win(game))
		close_game(game);
	return (0);
}