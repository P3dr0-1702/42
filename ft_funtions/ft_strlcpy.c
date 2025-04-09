/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:30:15 by pfreire-          #+#    #+#             */
/*   Updated: 2024/08/26 13:41:16 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *scr, unsigned int size)
{
	unsigned int	i;
	unsigned int	p;

	i = 0;
	p = 0;
	while (scr[p] != '\0')
		p++;
	if (size == 0)
		return (p);
	while (scr[i] != '\0' && i < size - 1)
	{
		dest[i] = scr[i];
		i++;
	}
	dest[i] = '\0';
	return (p);
}
