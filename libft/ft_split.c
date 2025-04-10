/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:58:54 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/10 11:57:48 by pfreire-         ###   ########.fr       */
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

int	ft_word_size(const char *s, char c)
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

char	*ft_wordcpy(const char **s, char c)
{
	char	*dest;
	int		counter;

	counter = 0;
	while (**s == c)
		(*s)++;
	while (**s != c)
	{
		counter++;
		(*s)++;
	}
	dest = malloc(sizeof(char) * (counter + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, ((*s) - counter), counter + 1);
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		wordnbr;
	int		i;

	i = -1;
	wordnbr = ft_count_words(s, c);
	array = malloc(sizeof(char *) * (wordnbr + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < wordnbr)
	{
		array[i] = ft_wordcpy(&s, c);
		if(array[i] == NULL)
			return (i_wanna_break_free(array), NULL);
		i++;
	}
	array[i] = NULL;
	return (array);
}