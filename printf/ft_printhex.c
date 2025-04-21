/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:21:17 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/21 15:46:07 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_hexadrs(unsigned long nb, int *n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
		ft_putnbr_hexadrs(nb / 16, n);
	ft_putchar(hex[nb % 16], n);
}

void	ft_printhex(void *ptr, int *n)
{
	unsigned long	i;

	i = (unsigned long)ptr;
	if (ptr == NULL)
	{
		ft_putstr("(nil)", n);
		return ;
	}
	ft_putchar('0', n);
	ft_putchar('x', n);
	ft_putnbr_hexadrs(i, n);
}
