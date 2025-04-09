/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:03:45 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/09 14:13:43 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < ft_strlen(s))
	{
		if (i == start)
		{
			substr = malloc(len);
			j = 0;
			while (j <= len)
			{
				substr[j] = s[i];
				j++;
				i++;
			}
			return (substr);
		}
		i++;
	}
	return (NULL);
}
