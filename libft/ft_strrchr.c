/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:17:44 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/07 12:31:01 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *strrchr(const char *a, int b)
{
	int i;
	char *f;

	i = ft_strlen(a);
	while (i >= 0)
	{
		if(a[i] == b)
		{
			f = a[i];
			return (f);
		}
		i--;
	}
	return (NULL);
}
