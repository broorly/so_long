/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:11:03 by mrafik            #+#    #+#             */
/*   Updated: 2022/05/21 13:57:00 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../ft_printf.h"

int	check1(char c, va_list x)
{
	int	count;

	count = 0;
	if (c == 's')
		count = ft_putstr(va_arg(x, char *));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(x, int));
	else if (c == 'c')
		count = ft_putchar(va_arg(x, int));
	else if (c == 'u')
		count = ft_hexa(va_arg(x, unsigned int), "0123456789", 10);
	else if (c == 'x')
		count = ft_hexa(va_arg(x, unsigned int), "0123456789abcdef", 16);
	else if (c == 'p')
	{
		count = ft_putstr("0x");
		count += ft_p(va_arg(x, unsigned long long));
	}
	else if (c == 'X')
		count = ft_hexa(va_arg(x, unsigned int), "0123456789ABCDEF", 16);
	else if (c == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	x;
	int		i;
	int		count;

	count = 0;
	va_start(x, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			count += check1(s[i], x);
			i++;
		}
		else
		{
			count += ft_putchar(s[i]);
			i++;
		}
	}
	va_end(x);
	return (count);
}
