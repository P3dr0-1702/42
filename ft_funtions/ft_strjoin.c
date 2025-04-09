/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_old.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 03:51:31 by pfreire-          #+#    #+#             */
/*   Updated: 2024/09/04 03:52:51 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	len(char **strs, int size)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (i < size)
	{
		a = a + ft_strlen(strs[i]);
		i++;
	}
	return (a);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		total_len;
	char	*buffer;

	total_len = len(strs, size) + (ft_strlen(sep) * (size - 1)) + 1;
	i = 0;
	if (size == 0)
	{
		buffer = malloc(sizeof(char));
		buffer = 0;
		return (buffer);
	}
	buffer = malloc(total_len);
	if (buffer == NULL)
		return (NULL);
	*buffer = 0;
	while (i < size)
	{
		ft_strcat(buffer, strs[i]);
		if (i < size -1)
			ft_strcat(buffer, sep);
		i++;
	}
	return (buffer);
}

/*#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	main(void)
{
	char	*result;
	char	*strs[] = {"Hello", "world", "from", "42"};
	char	sep[] = " ";
	int	size;

	// Test with size > 0
	size = 4;
	result = ft_strjoin(size, strs, sep);
	if (result)
	{
		printf("Test 1 (Size = %d):\n%s\n", size, result);
		free(result);  // Don't forget to free the allocated memory
	}
	else
	{
		printf("Test 1: Memory allocation failed\n");
	}

	// Test with size = 0
	size = 0;
	result = ft_strjoin(size, strs, sep);
	if (result)
	{
		printf("Test 2 (Size = %d):\n'%s'\n", size, result);
		free(result);  // Free the allocated memory
	}
	else
	{
		printf("Test 2: Memory allocation failed\n");
	}

	// Test with size = 1 (only one string, no separator)
	size = 1;
	result = ft_strjoin(size, strs, sep);
	if (result)
	{
		printf("Test 3 (Size = %d):\n%s\n", size, result);
		free(result);  // Free the allocated memory
	}
	else
	{
		printf("Test 3: Memory allocation failed\n");
	}

	return 0;
}
*/
