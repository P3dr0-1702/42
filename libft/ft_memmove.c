/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:32:05 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/07 10:41:12 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t i)
{
	size_t j;	
	size_t k;
	unsigned char *source;
	unsigned char *destin;

	destin = (unsigned char *)dest;
	source = (unsigned char *)src;
	j = 0;
	k = 0;
	while(destin[j] != '\0')
		j++;
	while(k < i)
	{
		destin[j] = source[k];
		k++;
		j++;
	}
	return (dest);
}