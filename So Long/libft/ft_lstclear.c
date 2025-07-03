/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:43:39 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/17 12:36:44 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Clears whole list
/// @param lst list
/// @param del funtion for deletion
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*i;
	t_list	*a;

	i = *lst;
	while (i != NULL)
	{
		(*del)(i->content);
		a = i->next;
		free(i);
		i = a;
	}
	*lst = NULL;
}
