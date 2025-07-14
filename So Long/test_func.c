/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:42:53 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/14 17:28:20 by pfreire-         ###   ########.fr       */
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
	ft_printf("┌──────── Window ─────────┐\n");
	ft_printf("  Window Pointer : %p\n", win->win_ptr);
	ft_printf("  Dimensions     : %d × %d px\n", win->width, win->height);
	ft_printf("  Tiles (X × Y)  : %d × %d\n", win->ntilesx, win->ntilesy);
	ft_printf("┌─ Frame Buffer ────────┐\n");
	print_image(&win->frame_buffer);
	ft_printf("└───────────────────────┘\n");
	ft_printf("└─────────────────────────┘\n");
}

char	*y_or_n(bool a)
{
	if (a)
		return ("Yes");
	return ("No");
}

void	print_player(t_player *player)
{
	ft_printf("┌────── Player ───────────┐\n");
	print_image(&player->sprite);
	print_point(&player->coord);
	ft_printf("    Boxed         : %s\n", y_or_n(player->boxed));
	ft_printf("    Immune        : %s\n", y_or_n(player->immune));
	ft_printf("    Immunity Time : %.2f s\n", player->immune_time);
	ft_printf("    Collectibles  : %d\n", player->collectibles);
	ft_printf("    Moves         : %d\n", player->moves);
	ft_printf("└─────────────────────────┘\n");
}

void	print_guard(t_guard *guard)
{
	print_image(&guard->sprite);
	print_point(&guard->coord);
	ft_printf("    Stationary    : %s\n", y_or_n(guard->is_stationary));
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	ft_printf("┌──────── Map ───────────┐\n");
	ft_printf("  Raw String     :\n%s\n", map->map);
	if (map->grid)
	{
		ft_printf("  Grid Layout:\n");
		while (map->grid[i])
		{
			ft_printf("    %s\n", map->grid[i]);
			i++;
		}
	}
	else
	{
		ft_printf("  Grid Layout    : No Valid Grid\n");
	}
	ft_printf("└─────────────────────────┘\n");
}

void	print_guards(t_game *s)
{
	int	i;

	i = 0;
	if (s->guard_count == 0)
	{
		ft_printf("No Guards to Show\n");
		return ;
	}
	ft_printf("┌──── Guards (%d) ────────┐\n", s->guard_count);
	while (i < s->guard_count)
	{
		ft_printf("  Guard #%d:\n", i + 1);
		print_guard(&s->guards[i]);
		i++;
	}
	ft_printf("└─────────────────────────┘\n");
}

void	print_collectible(t_collect *s)
{
	char	*status;

	status = "Inactive";
	if (s->active)
		status = "Active";
	ft_printf("Active Status: %s\n", status);
	print_point(&s->coord);
}

void	print_collectibles(t_game *s)
{
	int	i;

	i = 0;
	if (s->collectibles.count == 0)
		ft_printf("No Collectibles to Show\n");
	ft_printf("┌─── Collectibles (%d) ────────────┐\n", s->collectibles.count);
	print_image(&s->collectibles.sprite);
	while (i < s->collectibles.count)
	{
		ft_printf("┌─── Collectible #%d───┐\n", i + 1);
		print_collectible(&s->collectibles.collectible[i]);
		ft_printf("└──────────────────────┘\n");
		i++;
	}
	ft_printf("└─────────────────────────────────┘\n");
}

void	print_game(t_game *s)
{
	ft_printf("\n========== GAME STATE ==========\n");
	ft_printf("MLX Context Pointer: %p\n", s->mlx_ptr);
	ft_printf("┌──────── Game Base ──────┐\n");
	print_image(&s->base);
	ft_printf("└─────────────────────────┘\n");
	print_window(&s->win);
	print_map(&s->map);
	print_player(&s->player);
	print_guards(s);
	print_collectibles(s);
	ft_printf("========== END OF DUMP ==========\n\n");
}
