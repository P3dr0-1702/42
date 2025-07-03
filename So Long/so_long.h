/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:10:42 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/03 15:10:36 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "minilibx/mlx_int.h"
#include <X11/Xlib.h>

typedef enum e_player_state
{
	BOXED,
	UNBOXED,
	IMMUNE
}					t_snake_is;

typedef struct s_anim
{
	void			*idle;
	void			*move;
}					t_anim;

typedef struct s_snake
{
	int				x;
	int				y;
	int				colectibles;
	int				steps;
	char *img_adrr;
	
	t_snake_is		mode;
	t_anim			anims[2][4];
	int				direction;
	int				is_moving;
}					t_player;

typedef enum e_game_state
{
	GS_NORMAL,
	GS_CAUTIOUS
}					t_game_state;

typedef struct s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_addr;
	int				bits_per_pixel;
	int				line_leght;
	int				endian;
	int				width;
	int				height;
	t_game_state	game_state;
	t_player		*player;
}					t_window;

typedef struct s_point
{
	int				x;
	int				y;
}					point;

bool	is_valid(char *map);