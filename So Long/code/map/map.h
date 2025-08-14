/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:17:42 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/14 10:23:50 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../../so_long.h"

int		is_top(char *map);
int		is_bottom(char *map);
bool	is_first_line(char *map, int i);
void	*which_ground(t_game *s, int i);
void	*which_sprite(t_game *s, int i);

bool	at_least_one_collectible(char *map);
bool	only_one_player(char *map);
bool	only_one_exit(char *map);
bool	is_ber(char *str);

bool	no_forbidden_chars(char *map);
void	flood_fill(char **map, int *n, t_point point, bool *exit);
bool	pre_flood_fill(char *map);
bool	is_valid(char *map);
char	*map_parser(char **argv);

int		arr_len(char **s);
bool	bounds(char *map);
int		my_strlen(char *s);
bool	enough_objects(char *map);
bool	good_char(char c);

bool	is_rectangle(char **map);
bool	one_word_one(char *str);
bool	only_ones(char *str);
bool	is_closed(char *map);
t_point	p_coord(char **s);

#endif