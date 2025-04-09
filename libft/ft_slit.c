/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:58:54 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/09 17:43:19 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	i_wanna_break_free(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

int	ft_count_words(char const *s, char c)
{
	int		i;
	int		count;
	bool	word;

	i = 0;
	word = false;
	count = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			word = false;
		else if (!word)
		{
			word = true;
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_word_size(char *s, char c, int word_id)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i + j] != c)
	{
		j++;
	}
	return (j);
}

char	*ft_wordcpy(char **s, char c, int word_id)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (*s == c)
		(*s)++;
	while (*s != c)
		(*s)++;
	dest = malloc();
	while (word_id > 0)
	{
		if (s[i] == c && s[i - 1] != c)
			word_id--;
	}
	while (s[i + j] != '\0' || (s[i + j] == c && s[i + j - 1] == c))
	{
		dest[j] = s[i + j];
		j++;
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		wordnbr;
	int		i;

	i = -1;
	wordnbr = ft_count_words(s, c);
	array = malloc(sizeof(char) * (wordnbr + 1));
	if (!array)
		return (NULL);
	while (++i < wordnbr)
	{
		array[i] = malloc(sizeof(char) * (ft_word_size(s, c, i) + 1));
		if (!array[i])
			return (i_wanna_break_free(array), NULL);
	}
	i = 0;
	while (i < wordnbr)
	{
		array[i] = ft_wordcpy(&s, c, i);
		i++;
	}
	array[1 + i] = NULL;
	return (array);
}

#include <stdio.h>

int	main(void)
{
	char *s = "    Hoje o pedro tropecou no xao";
	char **res;

	printf("count workds = %d\n ", ft_count_words(s, ' '));
	res = ft_split(s, ' ');
	int i = -1;
	while (res[++i])
		printf("str = %s", res[i]);
}