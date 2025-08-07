/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_aux_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:41:22 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/07 09:53:07 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_point(t_point *p)
{
	ft_printf("  Position:\n");
	ft_printf("    X Coordinate   : %d\n", p->x);
	ft_printf("    Y Coordinate   : %d\n", p->y);
	ft_printf("    Tile X Index   : %d\n", p->tile_x);
	ft_printf("    Tile Y Index   : %d\n", p->tile_y);
}

void	print_image(t_image *img)
{
	ft_printf("    Image Details:\n");
	ft_printf("      Address      : %p\n", img->img_addr);
	ft_printf("      Pointer      : %p\n", img->img_ptr);
	ft_printf("      Width        : %d px\n", img->width);
	ft_printf("      Height       : %d px\n", img->heigth);
	ft_printf("      Bits/Pixel   : %d\n", img->bpp);
	ft_printf("      Line Length  : %d\n", img->l_len);
	ft_printf("      Endian       : %d\n", img->endian);
}

void	print_window(t_window *win)
{
	ft_printf("┌───────────────────────── Window ─────────────────────────┐\n");
	ft_printf("  Window Pointer : %p\n", win->win_ptr);
	ft_printf("  Dimensions     : %d × %d px\n", win->width, win->height);
	ft_printf("  Tiles (X × Y)  : %d × %d\n", win->ntilesx, win->ntilesy);
	ft_printf("┌─────── Frame Buffer ───────┐\n");
	print_image(&win->frame_buffer);
	ft_printf("└────────────────────────────┘\n");
	ft_printf("└──────────────────────────────────────────────────────────┘\n");
}

void	print_player(t_player *p)
{
	ft_printf("┌─────────────────────── Player Data ──────────────────────┐\n");
	ft_printf("┌────── Frame Data ───────┐\n");
	ft_printf("Under Construction: \n");
	ft_printf("└─────────────────────────┘\n");
	print_point(&p->coord);
	printf("   Collectibles Collected: %d\n", p->collectibles);
	printf("   Moves: %d\n", p->moves);
	ft_printf("└──────────────────────────────────────────────────────────┘\n");
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	ft_printf("┌─────────────────────────── Map ──────────────────────────┐\n");
	ft_printf("  Raw String     :\n%s\n", map->map);
	if (map->grid)
	{
		ft_printf("┌─────────── Grid ───────────┐\n");
		while (map->grid[i])
		{
			ft_printf("    %s\n", map->grid[i]);
			i++;
		}
		ft_printf("└────────────────────────────┘\n");
	}
	else
		ft_printf("No Valid Grid to Show\n");
	ft_printf("└──────────────────────────────────────────────────────────┘\n");
}
