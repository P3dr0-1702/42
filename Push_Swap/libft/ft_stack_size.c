/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:13:14 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/18 15:20:12 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stacksize(t_stack *lst)
{
	t_stack	*i;
	int		counter;

	if (!lst)
		return (0);
	i = lst;
	counter = 0;
	while (i)
	{
		i = i->next;
		counter++;
	}
	return (counter);
}
