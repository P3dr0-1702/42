/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:33:10 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/07 09:55:00 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_pixel_put(t_image *s, int x, int y, unsigned int color)
{
	char	*dest;

	dest = s->img_addr + (y * s->l_len + x * (s->bpp / 8));
	*(unsigned int *)dest = color;
}

int	pixel_get(t_image *data, int x, int y)
{
	char	*dest;

	dest = data->img_addr + (y * data->l_len + x * (data->bpp / 8));
	return (*(unsigned int *)dest);
}
