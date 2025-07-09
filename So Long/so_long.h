/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:52:37 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/09 17:15:19 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "minilibx/mlx_int.h"
#include <sys/time.h>

typedef struct s_point
{
	int	x;
	int	y;
	int tile_x;
	int tile_y;
}	t_point;

typedef struct s_image
{
	char *img_addr;
	int width;
	int heigth;
	int bpp;
	int l_len;
	int endian;
	int *img_ptr;
}	t_image;

typedef struct s_window
{
	void *win_ptr;
	int	width;
	int	height;
	int ntilesx;
	int ntilesy;
	t_image frame_buffer;
}	t_window;

typedef struct s_map
{
	char *map;
	char **grid;
}	t_map;

typedef struct s_snake
{
	t_image	sprite;
	t_point	coord;
	bool	boxed;
	bool	immune;
	double	immune_time;
	char *anim;
	int collectibles;
}	t_player;

typedef struct s_guard
{
	t_image	sprite;
	t_point	coord;
	bool	is_stationary;
}	t_guard;

typedef struct s_game
{
	void *mlx_ptr;
	t_window win;
	t_map	map;
	t_image  base;
	t_player	player;
	t_guard *guards;
	int guard_count;
}	t_game;

void print_game(t_game *s);

char	*map_parser(char **argv);
bool	is_valid(char *map);

int	firstline(char *map);
int	rng(void);
int	xtile(char *map);
int	ytile(char *map);


char *store_map(char *map);

void make_window(t_game *s);

void	init_game(t_game *s);
void	init_base(t_game *s);
void	init_player(t_game *s);

void render_frame(t_game *s);

void	*which_sprite(t_game *s, int i);


void	ft_pixel_put(t_image *s, int x, int y, unsigned int color);
int	pixel_get(t_image *data, int x, int y);