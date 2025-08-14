/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:38:13 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/14 10:16:41 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "../../so_long.h"

void	print_point(t_point *p);
void	print_image(t_image *img);
void	print_window(t_window *win);
void	print_player(t_player *p);
void	print_map(t_map *map);
void	*debug_limits(t_game *s, int i);

#endif