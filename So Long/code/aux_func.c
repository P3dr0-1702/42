/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:21:39 by pfreire-          #+#    #+#             */
/*   Updated: 2025/08/14 11:16:50 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	firstline(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		i++;
	return (i);
}

int	rng(void)
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

int	xtile(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n' && map[i] != '\0')
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
	if (map[i - 1] != '\n')
		count++;
	return (count);
}
