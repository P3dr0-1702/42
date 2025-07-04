/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:10:42 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/04 19:11:17 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "minilibx/mlx_int.h"
#include <X11/Xlib.h>
#include <sys/time.h>

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
	int				x;
	int				y;
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
	int x, y;
	bool			is_stationary;
	t_guard_state	state;
	double			state_timer;
	int				target_x;
	int				target_y;
}					t_guard;

typedef struct s_point
{
	int				x;
	int				y;
}					point;

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