/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:50:07 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/17 15:21:57 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static	buffer[BUFFER_SIZE + 1];
	char *str;
	int i;
	char c;

	if (read(fd, &c, BUFFER_SIZE) <= 0)
	{
		while(i < BUFFER_SIZE)
			buffer[i++]= '\0';
		return (NULL);
	}
	
}
