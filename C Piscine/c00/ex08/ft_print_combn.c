/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:23:12 by pfreire-          #+#    #+#             */
/*   Updated: 2024/09/04 11:44:56 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	comb(int start, int n)
{
	int	i;

	if (n == 0)
	{
		ft_putchar(',');
		ft_putchar(' ');
		return;
	}
	i = start + 1;
	while (i < 10)
	{
		ft_putchar(start + '0');
		ft_putchar(i + '0');
		comb(i, n - 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	comb(0, n);
}

int main ()
{
	ft_print_combn(2);
}
