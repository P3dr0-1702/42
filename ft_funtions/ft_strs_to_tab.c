/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:02:13 by pfreire-          #+#    #+#             */
/*   Updated: 2024/09/05 11:39:58 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int			n;
	char		*dest;

	n = ft_strlen(src);
	dest = malloc(n * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*strs;
	int					i;

	i = 0;
	strs = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (strs == NULL)
		return (NULL);
	while (i < ac)
	{
		if (av[1] == NULL)
			return (NULL);
		strs[i].str = ft_strdup(av[i]);
		strs[i].size = ft_strlen(av[i]);
		strs[i].copy = ft_strdup(av[i]);
		if (strs[i].str == NULL || strs[i].copy == NULL)
			return (NULL);
		i++;
	}
	strs[i].str = 0;
	free(strs);
}
