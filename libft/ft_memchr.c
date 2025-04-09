/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:22:56 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/07 11:28:54 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *a, int b, size_t c)
{
	size_t i;
	unsigned char *str;

	str = (unsigned char *)a;
	while (i < c)
	{
		if (str[i] == b)
		{
			return (str[i]);
		}
		i++;
	}
	return (NULL);
}