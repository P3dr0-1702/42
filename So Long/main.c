/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:39:10 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/04 16:45:04 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pixel_put(t_player*s, int x, int y, int color)
{
	char	*dest;

	dest = s->sprite.img_addr + (y * s->sprite.line_len + x * (s->sprite.bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

int pixel_get(t_image *data, int x, int y)
{
	char *dest;

	dest = data->img_addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	return(*(unsigned int *) dest);
}

void render_player(t_player *pla)
{
	int x;
	int y;
	unsigned int color;
	y = 0;
	while (y < pla->sprite.height)
	{
		x = 0;
		while(x < pla->sprite.width)
		{
			color = pixel_get(&pla->sprite, x, y);
			if((color >> 24) != 0xFF)
			{
				ft_pixel_put(pla, pla->x + x, pla->y + y, color);
			}
			x++;
		}
		y++;
	}
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

int	random_number(void)
{
	struct timeval	tv;
	struct timeval	tv2;
	int i;

	gettimeofday(&tv, NULL);
	i = 0;
	while(i < tv.tv_usec)
		i++;
	gettimeofday(&tv2, NULL);
	return (tv.tv_usec * tv2.tv_usec);
}

int	firstline(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		i++;
	return (i);
}

bool	should_put_wall(char *map, int i)
{
	if ((map[i - 1] == '\n' || map[i + 1] == '\n' || map[i + 1] == '\0' || i == 0)
		|| (map[i + 1] == '1' && map[i - 1] == '1'))
		return (true);
	return (false);
}

bool	is_first_line(char *map, int i)
{
	if ((map[i - 1] != '\0' && map[i + 1] != '\n') && map[i - 1] != '\n'
		&& i < firstline(map))
		return (true);
	return (false);
}

void	*which_sprite(t_game *s, int i)
{
	if (s->map.map[i] == 'B')
		return (mlx_xpm_file_to_image(s->win.mlx_ptr, "assets/walls/Wall3.xpm",
				&s->win.width, &s->win.height));
	else if (s->map.map[i] == 'M')
		return (mlx_xpm_file_to_image(s->win.mlx_ptr, "assets/walls/Wall2.xpm",
				&s->win.width, &s->win.height));
	else if (s->map.map[i] == 'W')
		return (mlx_xpm_file_to_image(s->win.mlx_ptr, "assets/walls/Wall1.xpm",
				&s->win.width, &s->win.height));
	else if (s->map.map[i] == 'X')
		return (mlx_xpm_file_to_image(s->win.mlx_ptr, "assets/Box.xpm", &s->win.width,
				&s->win.height));
	else
		return (mlx_xpm_file_to_image(s->win.mlx_ptr, "assets/Ground.xpm",
				&s->win.width, &s->win.height));
}

void	render_base(t_game *s)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	s->win.width = 64;
	s->win.height = 64;
	while (s->map.map[i] != '\0')
	{
		s->background.img_ptr = which_sprite(s, i);
		mlx_put_image_to_window(s->win.mlx_ptr, s->win.win_ptr, s->background.img_ptr, x, y);
		x += 128;
		if (s->map.map[i] == '\n')
		{
			y += 128;
			x = 0;
		}
		i++;
	}
}

char	pick_wall(char *map, int i)
{
	if (is_first_line(map, i) && random_number() % 7 == 1)
		return ('B');
	else if (is_first_line(map, i) && random_number() % 3 == 0)
		return ('M');
	else if (should_put_wall(map, i))
		return ('W');
	else
		return('X');
}

char	*store_base(char *map)
{
	int	i;
	int	x;
	int	y;
	char *str;

	i = 0;
	x = 0;
	y = 0;
	str = malloc(sizeof(char) * ft_strlen(map));
	while (map[i] != '\0')
	{
		if (map[i] == '1')
			str[i] = pick_wall(map, i);
		else
			str[i] = map[i];
		i++;
	}
	return (str);
}

char *make_window(t_game *s)
{
	s->win.width = 128 * xtile(s->map.map);
	s->win.height = 128 * ytile(s->map.map);
	s->win.win_ptr = mlx_new_window(s->win.mlx_ptr, s->win.width, s->win.height,
			"TAS: Metal Gear");
	s->map.map = store_base(s->map.map);
	return (s->map.map);
}

void init_player(t_game *s)
{
	s->player.sprite.img_ptr= mlx_xpm_file_to_image(s->win.mlx_ptr, "assets/Solid_Snake.xpm", &s->player.sprite.width, &s->player.sprite.height);
	s->player.sprite.img_addr = mlx_get_data_addr(s->player.sprite.img_ptr, &s->player.sprite.bits_per_pixel, &s->player.sprite.line_len, &s->player.sprite.endian);
	render_player(&s->player);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (argc != 2)
		return (-1);
	game->map.map = map_parser(argv);
	if (!is_valid(game->map.map))
		printf("Error\n");
	game->win.mlx_ptr = mlx_init();
	game->map.map = make_window(game);
	// game->background.img_ptr = mlx_xpm_file_to_image(game->win.mlx_ptr, "assets/Solid_Snake.xpm",
	// 		&game->win.width, &game->win.height);
	// mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->background.img_ptr, 10, 10);
	render_base(game);
	init_player(game);
	sleep(500);
	//mlx_loop(game->win.mlx_ptr);
	free(game);
}
