/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:36:57 by pfreire-          #+#    #+#             */
/*   Updated: 2024/09/01 14:31:17 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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

char	*ft_strdup(char *src)
{
	char	*buffer;
	int		sizesrc;

	sizesrc = ft_strlen(src);
	buffer = malloc((sizesrc * sizeof(char)) + 1);
	if (buffer == NULL)
		return (NULL);
	ft_strcpy(buffer, src);
	return (buffer);
}
/*int main(void)
{
    char src[] = "Hello, World!";
    char *dup;

    dup = ft_strdup(src);
    if (dup != NULL)
    {
        printf("%s\n", dup);
    }
    else
    {
        printf("failed memory allocation\n");
    }

    return 0;
}*/
