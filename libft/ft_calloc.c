/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:37:40 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/07 11:49:41 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	int *buffer;
	size_t i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if (nmemb * size > 2 ^ (64 - 1))
		return (-1);
	buffer = malloc(nmemb * size);
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		buffer[i] = 0;
		i++;
	}
	return (buffer);
}