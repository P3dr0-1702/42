/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:26:25 by pfreire-          #+#    #+#             */
/*   Updated: 2025/07/08 11:35:20 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_case(char a, va_list *arg, int *n)
{
	if (a == 'c')
		ft_putchar(va_arg(*arg, int), n);
	else if (a == 's')
		ft_putstr(va_arg(*arg, char *), n);
	else if (a == 'p')
		ft_printhex(va_arg(*arg, void *), n);
	else if (a == 'd')
		ft_putnbr(va_arg(*arg, int), n);
	else if (a == 'i')
		ft_putnbr(va_arg(*arg, int), n);
	else if (a == 'u')
		ft_putunbr(va_arg(*arg, unsigned int), n);
	else if (a == 'x')
		ft_putnbr_hexlow(va_arg(*arg, unsigned int), n);
	else if (a == 'X')
		ft_putnbr_hex(va_arg(*arg, unsigned int), n);
	else if (a == '%')
		ft_putchar('%', n);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		char_nbr;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	char_nbr = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			ft_case(format[i + 1], &args, &char_nbr);
			i += 2;
			continue ;
		}
		ft_putchar(format[i], &char_nbr);
		i++;
	}
	va_end(args);
	return (char_nbr);
}
