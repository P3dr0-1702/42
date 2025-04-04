/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:49:20 by pfreire-          #+#    #+#             */
/*   Updated: 2024/09/04 02:27:03 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;
	int	*buffer;

	i = 0;
	if (min >= max)
	{
		buffer = NULL;
		return (0);
	}
	size = max - min;
	buffer = malloc(size * sizeof(int));
	if (!buffer)
		return (-1);
	while (i < size)
	{
		buffer[i] = min + i;
		i++;
	}
	*range = buffer;
	return (size);
}
/*
int	main(void)
{
	int *range;
	int size;
	int i;
	int min;
	int max;

	min = 3;
	max = 8;
	size = ft_ultimate_range(&range, min, max);
	i = 0;
	while (i < size)
	{
		printf("%d ", range[i]);
		i++;
	}

	return (0);
}*/
