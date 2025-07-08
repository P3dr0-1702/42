/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:19:49 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/08 13:20:19 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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