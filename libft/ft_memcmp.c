/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:31:38 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/11 12:07:40 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;
	char *a;
	char *b;

	i = 0;
	a = (char *)s1;
	b = (char *)s2;
	while(i < n)
	{
		if(a[i] != b[i])
		{
			return(a - b);
		}
		i++;
	}
	return (0);
}
