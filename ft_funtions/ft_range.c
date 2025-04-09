/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:32:17 by pfreire-          #+#    #+#             */
/*   Updated: 2024/09/04 00:26:23 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*buffer;
	int	size;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	size = max - min;
	buffer = malloc(size * sizeof(int));
	if (buffer == NULL)
		return (NULL);
	while (i < size)
	{
		buffer[i] = min + i;
		i++;
	}
	return (buffer);
}
/*int main()
{
    int min = 5;
    int max = 15;
    int *range;
    int size;
    int i;

    range = ft_range(min, max);
    if (range == NULL) {
        printf("Error: Memory allocation failed or invalid range.\n");
        return 1;
    }

    size = max - min;
    printf("Range from %d to %d:\n", min, max);
    for (i = 0; i < size; i++) {
        printf("%d ", range[i]);
    }
    printf("\n");

    free(range);
    return 0;
}*/
