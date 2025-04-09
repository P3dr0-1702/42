/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 08:55:19 by pfreire-          #+#    #+#             */
/*   Updated: 2024/08/27 16:55:50 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	ft_strlowcase(str);
	i = 0;
	while (str[i] != '\0')
	{
		j = i - 1;
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (!((str[j] >= '0' && str[j] <= '9')
					|| (str[j] >= 'a' && str[j] <= 'z')
					|| (str[j] >= 'A' && str[j] <= 'Z')))
			{
				str[i] -= 32;
			}
		}
		i++;
	}
	return (str);
}
/*int main()
{
	char	str[] = "rekt*17+lol md/r mdr 4242l42";
	ft_strcapitalize(str);
	printf("%s\n", ft_strcapitalize(str));
}*/	
