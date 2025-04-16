/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:26:50 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/14 11:11:11 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*i;
	int		counter;

	i = lst;
	counter = 0;
	while (i != NULL)
	{
		i = i->next;
		counter++;
	}
	return (counter);
}
