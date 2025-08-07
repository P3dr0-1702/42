/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:30:00 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/07 11:32:13 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	keyloop(int key, t_game *game)
{
	if (key == KEY_R && game->debug_mode)
		print_game(game);
	if(key == 'q' || key == 65307)
		close_game(game);
	else if (key == KEY_A || key == KEY_LEFT)
	{
		move_left(game);
		ft_printf("Total moves: %d\n", game->player.moves);
	}
	else if (key == KEY_W || key == KEY_UP)
	{
		move_up(game);
		ft_printf("Total moves: %d\n", game->player.moves);
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
		move_right(game);
		ft_printf("Total moves: %d\n", game->player.moves);
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
		move_down(game);
		ft_printf("Total moves: %d\n", game->player.moves);
	}
	return (0);
}

int	gameloop(t_game *game)
{
	render_frame(game);
	if (game_win(game))
		close_game(game);
	return (0);
}

void	render_frame(t_game *s)
{
	clear_frame(s);
	render_base_into_buffer(s);
	render_collectibles_into_buffer(s);
	render_player_into_buffer(s);
	mlx_put_image_to_window(s->mlx_ptr, s->win.win_ptr,
		s->win.frame_buffer.img_ptr, 0, 0);
}