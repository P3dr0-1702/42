// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   enemy_AI.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/07/08 14:07:58 by pfreire-          #+#    #+#             */
// /*   Updated: 2025/07/08 14:29:23 by pfreire-         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "so_long.h"

// int **malloc_int_map(int width, int heght)
// {
// 	int **map;
// 	int y;
// 	int x;
// 	x = 0;
// 	x = 0;
// 	map = malloc(heght * sizeof(int *));
// 	while(y < heght)
// 	{
// 		map[y] = malloc(width * sizeof(int));
// 		x = 0;
// 		while(x < width)
// 		{
// 			map[y][x] = -1;
// 			x++;
// 		}
// 		y++;
// 	}
// 	return map;
// }

// point *create_queue(int capacity)
// {
// 	return(malloc(capacity*sizeof(point)));
// }

// int **flood_map_gen(t_guard guard, int height, int width)
// {
// 	int **guard_grid;
// 	int front;
// 	int back;
// 	point *queue;

// 	guard_grid = malloc_int_map(width, height);
// 	front = 0;
// 	back = 0;
// 	queue = create_queue(width * height);
// }
