/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:50:09 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/14 18:24:28 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
// #include "code/debug/debug.h"
// #include "code/init/init.h"
// #include "code/map/map.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include <sys/time.h>
#include <unistd.h>

#define MOVE_LEFT 0
#define MOVE_UP 1
#define MOVE_RIGHT 2
#define MOVE_DOWN 3
#define KEY_LEFT 65361
#define KEY_UP 65362
#define KEY_RIGHT 65363
#define KEY_DOWN 65364
#define KEY_A 97
#define KEY_W 119
#define KEY_D 100
#define KEY_S 115
#define KEY_R 114
#define KEY_Q 113
// Sprite Paths
#define ASSETS_PATH "assets/"
#define GROUND_PATH "assets/ground/"
#define WALL_PATH "assets/walls/"
#define ENT_PATH "assets/ent/"
#define OBSTACLES_PATH "assets/obstacles/"
// Floor
#define GROUND1 '0'
#define GROUND2 'O'
#define GROUND3 'V'
#define GROUND4 'W'
// Walls
#define KOJIMA_WALL 'K'
#define WALL '1'
#define WALL_PANEL 'T'
#define WALL_POSTER 'B'
#define WALL_SIGN 'S'
// Obstacles
#define BOX 'X'
#define DESTROYED_GROUND 'G'
#define OCTUPUSS '8'

typedef struct s_point
{
	int				x;
	int				y;
	int				tile_x;
	int				tile_y;
}					t_point;

typedef struct s_image
{
	char			*img_addr;
	int				width;
	int				heigth;
	int				bpp;
	int				l_len;
	int				endian;
	int				*img_ptr;
}					t_image;

typedef struct s_window
{
	void			*win_ptr;
	int				width;
	int				height;
	int				ntilesx;
	int				ntilesy;
	t_image			frame_buffer;
}					t_window;

typedef struct s_map
{
	char			*map;
	char			**grid;
}					t_map;

typedef struct s_snake
{
	t_image			sprite;
	t_point			coord;
	int				collectibles;
	unsigned int	moves;
}					t_player;

typedef struct s_ration
{
	t_point			coord;
	bool			active;
}					t_collect;

typedef struct s_collectibles
{
	t_collect		*collectible;
	t_image			sprite;
	int				count;
}					t_collectibles;

typedef struct s_game
{
	bool			debug_mode;
	void			*mlx_ptr;
	t_window		win;
	t_map			map;
	t_image			base;
	t_player		player;
	t_collectibles	collectibles;
}					t_game;

// Debugging
void				print_game(t_game *s);
bool				debug_mode(t_game *s, char **argv);
void				*debug_limits(t_game *s, int i);
// Aux Func
int					firstline(char *map);
int					rng(void);
int					xtile(char *map);
int					ytile(char *map);

// Map Parsing
char				*map_parser(char **argv);
bool				is_valid(char *map);

// Gameloop
int					gameloop(t_game *param);
int					keyloop(int key, t_game *game);

// Init Base
void				init_base(t_game *s);

// Init Colletibles
void				init_collectibles(t_game *s);
int					char_count(char *s, char c);

// Inititalizer
void				init_game(t_game *s);

// Map
char				*store_map(char *map);
char				pick_ground(char *map, int i);
void				*which_sprite(t_game *s, int i);
char				pick_wall(char *map, int i);

// Move
int					move_up(t_game *s);
int					move_down(t_game *s);
int					move_left(t_game *s);
int					move_right(t_game *s);
bool				game_win(t_game *s);
// Player
int					move(t_game *s, int dir);
void				collected(t_game *s);
// Rendering
void				render_frame(t_game *s);
void				render_base_into_buffer(t_game *s);
void				render_collectible_into_buffer(t_game *s, t_collect *c);
void				render_player_into_buffer(t_game *s);
void				render_collectibles_into_buffer(t_game *s);
void				clear_frame(t_game *s);

// Utils
void				ft_pixel_put(t_image *s, int x, int y, unsigned int color);
int					pixel_get(t_image *data, int x, int y);

int					close_game(t_game *param);

int					my_strlen(char *s);
void				free_grid(char **str);