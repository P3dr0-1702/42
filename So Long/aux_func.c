/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:22:59 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/08 13:20:16 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pixel_put(t_game *s, int x, int y, unsigned int color)
{
	char	*dest;

	dest = s->win.frame_buffer.img_addr + (y * s->win.frame_buffer.line_len + x
			* (s->win.frame_buffer.bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

int	pixel_get(t_image *data, int x, int y)
{
	char	*dest;

	dest = data->img_addr + (y * data->line_len + x * (data->bits_per_pixel
				/ 8));
	return (*(unsigned int *)dest);
}

int	firstline(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		i++;
	return (i);
}

int	random_number(void)
{
	struct timeval	tv;
	struct timeval	tv2;
	int				i;

	gettimeofday(&tv, NULL);
	i = 0;
	while (i < tv.tv_usec)
		i++;
	gettimeofday(&tv2, NULL);
	return (tv.tv_usec * tv2.tv_usec);
}
