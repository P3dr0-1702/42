/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:15:44 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/17 13:03:49 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	ft_printf("┌──────── Window ──────────────────┐\n");
	ft_printf("  Window Pointer : %p\n", win->win_ptr);
	ft_printf("  Dimensions     : %d × %d px\n", win->width, win->height);
	ft_printf("  Tiles (X × Y)  : %d × %d\n", win->ntilesx, win->ntilesy);
	ft_printf("┌─ Frame Buffer ────────┐\n");
	print_image(&win->frame_buffer);
	ft_printf("└───────────────────────┘\n");
	ft_printf("└──────────────────────────────────┘\n");
}

char	*y_or_n(bool a)
{
	if (a)
		return ("Yes");
	return ("No");
}

void print_player(t_player *p)
{	ft_printf("┌────────── Player Data ──────────┐\n");
	ft_printf("┌─────── Frame Data ──────┐\n");
	ft_printf("Under Construction: ");
	ft_printf("└─────────────────────────┘\n");
	print_point(&p->coord);
	printf("   Immunity Frames: %d\n", p->immunity_time);
	printf("   Collectibles Collected: %d\n", p->collectibles);
	printf("   Moves: %d\n", p->moves);
	ft_printf("└────────────────────────────────┘\n");

}


void	print_game(t_game *s)
{
	ft_printf("\n========== GAME STATE ==========\n");
	ft_printf("MLX Context Pointer: %p\n", s->mlx_ptr);
	ft_printf("┌──────── Game Base ───────────────┐\n");
	print_image(&s->base);
	ft_printf("└──────────────────────────────────┘\n");
	print_window(&s->win);
	print_map(&s->map);
	print_player(&s->player);
	print_guards(s);
	print_collectibles(s);
	ft_printf("========== END OF DUMP ==========\n\n");
}

bool	debug_mode(char **argv)
{
	if (argv[2])
	{
		if (ft_strcmp(argv[2], "debug_mode=y") == 0)
			return (true);
	}
	return (false);
}