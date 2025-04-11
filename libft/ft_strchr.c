/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:09:00 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/11 11:51:31 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *a, int b)
{
	int	i;

	i = 0;
	while (a[i] != '\0')
	{
		if (a[i] == (char)b)
			return ((char *)a + i);
		i++;
	}
	if (b == '\0')
		return ((char *)a + i);
	return (NULL);
}
// int	main(void)
// {
// 	char s[] = "bombardino crocodillo";
// 	printf("%s\n", ft_strchr(s, 'b'));
// }