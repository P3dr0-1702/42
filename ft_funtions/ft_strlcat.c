/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:49:09 by pfreire-          #+#    #+#             */
/*   Updated: 2024/08/31 10:11:07 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
	{
		return (size + src_len);
	}
	i = dest_len;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}
/*#include <stdio.h>


int main(void)
{
    char dest[50] = "Hello";
    char src[] = " World!";
    unsigned int size = 15;
    unsigned int result;

    printf("Before strlcat:\n");
    printf("dest = \"%s\"\n", dest);
    printf("src = \"%s\"\n", src);

    result = ft_strlcat(dest, src, size);

    printf("\nAfter strlcat:\n");
    printf("dest = \"%s\"\n", dest);
    printf("src = \"%s\"\n", src);
    printf("Total length = %u\n", result);
	
    return 0;
}*/
