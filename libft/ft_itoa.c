/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:02:45 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/14 11:03:10 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*min_int(void)
{
	char	*str;

	str = malloc(sizeof(char) * 12);
	if (!str)
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

static void	popul(int n, int size, char **str, int *i)
{
	int	j;

	j = 1;
	if (n < 0)
		j = 2;
	*str = malloc(size + j);
	if (!*str)
		return ;
	if (n < 0)
	{
		(*str)[0] = '-';
		*i = 1;
		n *= -1;
	}
	else
		*i = 0;
	(*str)[size + (j - 1)] = '\0';
}

static int	lenofn(int n)
{
	int	len;

	if (n < 0)
		n *= -1;
	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*nzero(void)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (n == 0)
		return (nzero());
	if (n == -2147483648)
		return (min_int());
	len = lenofn(n);
	popul(n, len, &str, &i);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
// int main()
// {
// 	int i = -0;
// 	char *str = ft_itoa(i);
// 	printf("%s\n", str);
// 	free(str);
// }