/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:20:03 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/09 14:13:31 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t n)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (i < n)
	{
		while (str[i] != '\0')
		{
			j = 0;
			while (str[i + j] == to_find[j] && to_find[j] != '\0')
				j++;
			if (to_find[j] == '\0')
				return (str + i);
			i++;
		}
	}
	return (NULL);
}

/*char *ft_strstr(char *str, char *to_find);

int	main(void)
{
	char str[] = "Hello, this is a simple string.";
	char to_find1[] = "simpjle";
	char to_find2[] = "test";
	char to_find3[] = "";
	char *result;

	// Test case 1: Substring is found
	result = ft_strstr(str, to_find1);
	if (result != NULL)
	{
		printf("Found '%s' in '%s': '%s'\n", to_find1, str, result);
	}
	else
	{
		printf("Substring '%s' not found in '%s'\n", to_find1, str);
	}

	// Test case 2: Substring is not found
	result = ft_strstr(str, to_find2);
	if (result != NULL)
	{
		printf("Found '%s' in '%s': '%s'\n", to_find2, str, result);
	}
	else
	{
		printf("Substring '%s' not found in '%s'\n", to_find2, str);
	}

	// Test case 3: Empty substring
	result = ft_strstr(str, to_find3);
	if (result != NULL)
	{
		printf("Found empty string in '%s': '%s'\n", str, result);
	}
	else
	{
		printf("Empty string not found in '%s'\n", str);
	}

	return (0);
}*/
