/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:49:08 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/10 11:01:02 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_iset(const char *set, char a)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (a == set[i])
			return (true);
		i++;
	}
	return (false);
}
char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strtrim(const char *s1, char const *set)
{
	int		i;
	int		f;
	char	*str;

	i = 0;
	f = ft_strlen(s1);
	while (s1[i] && ft_iset(set, s1[i]))
		i++;
	while (f > 0 && ft_iset(set, s1[f - 1]))
		f--;
	str = malloc(sizeof(char) * ((f - i) + 1));
	str = ft_strncpy(str, s1 + i, f - i);
	return (str);
}
