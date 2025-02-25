/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:49:57 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/24 15:08:00 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_calcul_base(unsigned long int n, char c)
{
	if (n == 0 && c == 'p')
		return (ft_putstr_printf("(nil)"));
	else if (n >= 1 && c == 'p')
		return (ft_putstr_printf("0x"));
	return (0);
}

static int	ft_putnbr_base(unsigned long int n, char c)
{
	char	*base;
	char	str[50];
	int		j;
	int		counter;

	j = 0;
	counter = ft_calcul_base(n, c);
	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	else if (c == 'u')
		base = "0123456789";
	if (n == 0 && c != 'p')
		str[j++] = '0';
	while (n >= 1)
	{
		str[j++] = base[n % ft_strlen_printf(base)];
		n /= ft_strlen_printf(base);
	}
	str[j] = '\0';
	while (--j >= 0)
		write(1, &str[j], 1);
	return (ft_strlen_printf(str) + counter);
}

static int	ft_verif(va_list params, char c)
{
	int	counter;

	counter = 0;
	if (c == '%')
		counter += ft_putchar_printf('%');
	else if (c == 'c')
		counter += ft_putchar_printf(va_arg(params, int));
	else if (c == 's')
		counter += ft_putstr_printf(va_arg(params, char *));
	else if (c == 'd' || c == 'i')
		ft_putnbr_printf(va_arg(params, int), &counter);
	else if (c == 'p')
		counter += ft_putnbr_base(va_arg(params, unsigned long int), c);
	else if (c == 'x' || c == 'X' || c == 'u')
		counter += ft_putnbr_base(va_arg(params, unsigned int), c);
	return (counter);
}

int	ft_printf(const char *f, ...)
{
	va_list	params;
	int		counter;

	counter = 0;
	va_start(params, f);
	if (!f)
		return (counter = -1, counter);
	while (*f)
	{
		if (*f == '%')
		{
			f++;
			counter += ft_verif(params, *f);
			f++;
		}
		else
		{
			counter += ft_putchar_printf(*f);
			f++;
		}
	}
	va_end(params);
	return (counter);
}
