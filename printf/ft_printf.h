/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:22:44 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/21 15:49:45 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_printhex(void *ptr, int *n);
void	ft_putchar(char c, int *n);
void	ft_putnbr_hex(unsigned int nb, int *n);
void	ft_putnbr_hexlow(unsigned int nb, int *n);
void	ft_putnbr(int nb, int *n);
void	ft_putstr(char *str, int *n);
void	ft_putunbr(unsigned int nb, int *n);
char	*ft_strlowcase(char *str, int *n);
int		ft_printf(const char *format, ...);

#endif
