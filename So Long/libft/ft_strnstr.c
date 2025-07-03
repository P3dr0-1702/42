/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:20:03 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/21 15:34:56 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if (!str || !to_find)
		return (NULL);
	if (to_find[0] == '\0')
		return ((char *)str);
	i = 0;
	while (i < n && (str[i] != '\0'))
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j] != '\0' && str[i
				+ j] != '\0' && i + j < n)
			j++;
		if (to_find[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
