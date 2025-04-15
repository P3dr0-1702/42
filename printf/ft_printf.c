/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:26:25 by pfreire-          #+#    #+#             */
/*   Updated: 2025/04/15 11:48:20 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	int char_nbr;

	va_start(args, format);
	i = 0;
	char_nbr = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			ft_case(format[i + 1], &args, &char_nbr);
			i += 2;
			continue;
		}
		ft_putchar(format[i], &char_nbr);
		i++;
	}
	va_end(args);
	return (char_nbr);
}

// int main()
// {
// 	char c = 'o';
// 	char s[]= "cao";
// 	int i = 55;
// 	unsigned int j = INT_MAX;
// 	ft_printf("%c %s fugiu de casa e foi para endereco %p, as %d e %i ele ganhou na loteria $%u\n ele contou o dinheiro e deu %x, %X!!!, %%",
// 	 c, s, (void*)42, i, (i - 10), j, i ,i);
// }
