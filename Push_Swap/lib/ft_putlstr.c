/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:53:32 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/21 15:37:00 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlstr(char *str, int *n)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putlstr("(null)", n);
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putlchar(str[i], n);
		i++;
	}
}
