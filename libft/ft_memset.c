/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:48:35 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/14 11:12:27 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *a, int c, size_t i)
{
	size_t			j;
	unsigned char	*str;

	str = (unsigned char *)a;
	j = 0;
	while (j < i)
	{
		str[j] = (unsigned char)c;
		j++;
	}
	return (a);
}
