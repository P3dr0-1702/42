/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:10:42 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/19 16:46:53 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "minilibx/mlx_int.h"
#include <X11/Xlib.h>
#include "lib/libft.h"

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	void *textures[5];
}	t_data;