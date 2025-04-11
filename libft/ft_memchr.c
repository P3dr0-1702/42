/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:22:56 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/11 12:02:28 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *a, int b, size_t c)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)a;
	while (i < c)
	{
		if (str[i] == (unsigned char)b)
		{
			return (str + i);
		}
		i++;
	}
	return (NULL);
}
// int main()
// {
// 	char s[] = "helllo world";
// 	char *f;
// 	f = ft_memchr(s, 'l', 3);
// 	printf("%s\n", f);
// }