/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:05:54 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/06 18:08:33 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(int i)
{
	if (i > 48 && i < 57)
		return (1);
	else
		return (0);
}