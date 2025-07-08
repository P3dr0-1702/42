/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:26:50 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/17 12:57:42 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Counts size of the list
/// @param lst list
/// @return size as an integer
int	ft_lstsize(t_list *lst)
{
	t_list	*i;
	int		counter;

	if (!lst)
		return (0);
	i = lst;
	counter = 0;
	while (i != NULL)
	{
		i = i->next;
		counter++;
	}
	return (counter);
}
