/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:17:44 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/11 12:08:59 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *a, int b)
{
	int i;

	i = ft_strlen(a);
	while (i >= 0)
	{
		if(a[i] == (char)b)
		{
			return ((char*) a + i);
		}
		i--;
	}
	return (NULL);
}
