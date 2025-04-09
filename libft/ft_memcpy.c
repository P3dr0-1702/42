/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:19:34 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/07 10:25:47 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memcpy(void *dest, const void *src, size_t i)
{
	size_t j;
	unsigned char *str;
	unsigned char *strdest;

	src = (unsigned char *) src;
	strdest = (unsigned char *) dest;
	while (j < i)
	{
		strdest[j] = str[j];
		j++;		 
	}
	return (dest);
}