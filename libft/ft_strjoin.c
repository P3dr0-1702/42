/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:24:59 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/09 14:28:58 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_strlen(char *str);

char *ft_strjoin(char const *s1, char const *s2)
{
	char *r1;
	int i;
	int j;
	
	r1 = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	i = 0;
	j = 0;
	while(i <= ft_strlen(s1))
	{
		r1[i] = s1[i];
		i++;
	}
	while (j <= ft_strlen(s2))
	{
		r1[i] = s2[j];
		i++;
		j++;
	}
	r1[i] = '\0';
	return r1;
	
}