/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:11:07 by mrafik            #+#    #+#             */
/*   Updated: 2022/05/21 13:52:34 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	unsigned int	nbr;
	int				i;

	i = 0;
	nbr = nb;
	if (nb < 0)
	{
		nbr = nb * (-1);
		i += ft_putchar('-');
	}	
	if (nbr >= 10)
	{
		i += ft_putnbr(nbr / 10);
	}
	i += ft_putchar(nbr % 10 + '0');
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		i = 6;
	}
	else
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	return (i);
}

int	ft_hexa(unsigned int nb, char *base, unsigned int b)
{
	int	c;

	c = 0;
	if (nb >= b)
	{
		c += ft_hexa(nb / b, base, b);
	}
	c += ft_putchar(base[nb % b]);
	return (c);
}

int	ft_p(unsigned long long nb)
{
	int		c;
	char	*base;

	base = "0123456789abcdef";
	c = 0;
	if (nb >= 16)
	{
		c += ft_p(nb / 16);
	}
	c += ft_putchar(base[nb % 16]);
	return (c);
}
