/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   --ft_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:24:21 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/09 16:58:22 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int		i;
	int		count;
	bool	word;

	i = 0;
	word = false;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			word = False;
		else if (!word)
		{
			word = true;
			count++;
		}
		i++;
	}
	return (count);
}

char **ft_split(char const *s, char c)
{
	char **array;
	int i;
	int wordnbr;

	wordnbr = ft_count_words(s, c);
}