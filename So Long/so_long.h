/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:10:42 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/08 14:29:08 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "minilibx/mlx_int.h"
#include <X11/Xlib.h>
#include <sys/time.h>


typedef struct s_point
{
	int				x;
	int				y;
}					point;

typedef struct s_image
{
	char			*img_addr;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				line_len;
	int				endian;
	void			*img_ptr;
}					t_image;

typedef struct s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			frame_buffer;
	t_image			background;
	int				width;
	int				height;
	int				tilex;
	int				tiley;
}					t_window;

typedef struct s_map
{
	char			*map;
	char			**grid;
	char			**guard_map;
}					t_map;

typedef struct s_snake
{
	t_image			sprite;
	point			coord;
	int				tilex;
	int				tiley;
	bool			boxed;
	bool			immune;
	double			immunity_time;
	int				collectibles;
}					t_player;

typedef enum e_guard_state
{
	GUARD_IDLE,
	GUARD_SUSPICIOUS,
	GUARD_ALERT,
	GUARD_STUNNED,
	GUARD_RETURNING
}					t_guard_state;

typedef struct s_guard
{
	t_image			sprite;
	point			cord;
	bool			is_stationary;
	t_guard_state	state;
	double			state_timer;
	int				target_x;
	int				target_y;
}					t_guard;

typedef struct s_game
{
	t_window		win;
	t_map			map;
	t_player		player;
	t_image			background;
	t_guard			*guards;
	int				guard_number;
	double			alert_cooldown;
}					t_game;

bool				is_valid(char *map);

// Auxiliary functions
void				ft_pixel_put(t_game *s, int x, int y, unsigned int color);
int					pixel_get(t_image *data, int x, int y);
int					firstline(char *map);
int					random_number(void);
int					xtile(char *map);
int					ytile(char *map);

// Initialization functions
void				init_player(t_game *s, int spawnx, int spawny);
t_image				init_tile(t_game *s, int i);
void				init_game(t_game *game);

// Map Parsing and Validation
bool				is_rectangle(char **map);
bool				one_word_one(char *str);
bool				only_ones(char *str);
bool				is_closed(char *map);
bool				only_one_player(char *map);
bool				only_one_exit(char *map);
bool				enough_objects(char *map);
bool				good_char(char c);
bool				no_forbidden_chars(char *map);
bool				is_valid(char *map);
bool				at_least_one_collectible(char *map);
char				*map_parser(char **argv);

// Player Functions

// Rendering
void				render_frame(t_game *s, int playerx, int playery);
void				render_base_buffer(t_game *s);
void				render_player_buffer(t_game *game);
void				fill_tile(t_game *g, t_image *tile, unsigned int color,
						int *coords);

// Sprite Picker
char				pick_wall(char *map, int i);
bool				should_put_wall(char *map, int i);
bool				is_first_line(char *map, int i);
void				*which_sprite(t_game *s, int i);
