/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:15:06 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/17 12:52:30 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Prints char in fd
/// @param c char
/// @param fd File Decriptor
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
