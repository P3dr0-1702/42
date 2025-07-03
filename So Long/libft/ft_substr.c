/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:03:45 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/14 11:05:17 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;
	size_t	siz;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	siz = len;
	if (ft_strlen(s) - start < len)
		siz = ft_strlen(s) - start;
	substr = malloc(sizeof(char) * (siz + 1));
	if (!substr)
		return (NULL);
	while (j < siz && s[i] != '\0')
	{
		substr[j] = s[i];
		j++;
		i++;
	}
	substr[j] = '\0';
	return (substr);
}

// int main()
// {
// 	char str[] = "tripouille";
// 	char *str2;
// 	str2 = (ft_substr(str, 0, 42000));
// 	printf("%s\n", str2);
// 	free(str2);
// }