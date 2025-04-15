/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:18:49 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/15 11:48:36 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_hex(unsigned int nb, int *n)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (nb >= 16)
		ft_putnbr_hex(nb / 16, n);
	ft_putchar(hex[nb % 16], n);
}
// int main()
// {
// 	int i;

// 	i = 0;
// 	while (i < 100)
// 	{
// 		ft_putnbr_hex(i, &i);
// 		printf("\n");
// 		i++;
// 	}
// }