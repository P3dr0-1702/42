/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:04:28 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/07 09:53:30 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H
# include "../../so_long.h"

t_image	init_tile_base(t_game *s, int i);
void	fill_tile(t_game *g, t_image *tile, unsigned int color, t_point point);
void	init_base(t_game *s);
int		char_count(char *s, char c);
void	init_collectible(t_collect *s, int x, int y);
void	init_collect(t_game *s);
void	init_collectibles(t_game *s);
void	spawn_point(t_game *s);
void	init_player_imgptr(t_game *s);
void	init_player_imgaddr(t_game *s);
void	init_map(t_game *s);
void	init_player(t_game *s);
void	init_window(t_game *s);
void	init_game(t_game *s);

#endif