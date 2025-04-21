/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:53:32 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/21 15:46:21 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *n)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", n);
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i], n);
		i++;
	}
}
