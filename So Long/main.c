/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:39:10 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/03 17:28:25 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pixel_put(t_window *s, int x, int y, int color)
{
	char	*dest;

	dest = s->img_addr + (y * s->line_leght + x * (s->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

char	*map_parser(char **argv)
{
	int		fd;
	char	*temp;
	char	*line;
	char	*map;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = ft_strdup("");
	while ((line = get_next_line(fd)) != NULL)
	{
		temp = ft_strjoin(map, line);
		free(map);
		map = temp;
		free(line);
	}
	close(fd);
	return (map);
}

int	xtile(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
	{
		i++;
	}
	return (i);
}

int	ytile(char *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

void	render_base(t_window *s, char *map)
{
	int	i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	s->width = 64;
	s->height= 64;
	while (map[i] != '\0')
	{
		s->img_ptr = mlx_xpm_file_to_image(s->mlx_ptr, "assets/Ground.xpm", &s->width, &s->height);
		if (map[i] == '1')
			s->img_ptr = mlx_xpm_file_to_image(s->mlx_ptr, "assets/Box.xpm", &s->width, &s->height);
		mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, x, y);
		x+=128;
		if(map[i] == '\n')
		{
			y += 128;
			x = 0;
		}
		i++;
	}
}

void	make_window(char *map, t_window *s)
{
	s->width = 128 * xtile(map);
	s->height = 128 * ytile(map);
	s->win_ptr = mlx_new_window(s->mlx_ptr, s->width, s->height,
			"TAS: Metal Gear");
	render_base(s, map);
}

int	main(int argc, char **argv)
{
	char		*map;
	t_window	*win;

	win = malloc(sizeof(t_window));
	// t_player	player;
	if (argc != 2)
		return (-1);
	map = map_parser(argv);
	if (!is_valid(map))
		printf("Error\n");
	win->mlx_ptr = mlx_init();
	make_window(map, win);
	win->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, "assets/Solid_Snake.xpm", &win->width, &win->height);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 10, 10);
	mlx_loop(win->mlx_ptr);
	free(map);
}
