/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:25:28 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/24 15:08:33 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_printf(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen_printf(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr_printf(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	write(1, s, ft_strlen_printf(s));
	return (ft_strlen_printf(s));
}

void	ft_putnbr_printf(int n, int *counter)
{
	if (n == -2147483648)
	{
		(*counter) += ft_putstr_printf("-2147483648");
		return ;
	}
	if (n < 0)
	{
		(*counter) += ft_putchar_printf('-');
		n *= -1;
	}
	if (n >= 0 && n <= 9)
		(*counter) += ft_putchar_printf(n + '0');
	if (n > 9)
	{
		ft_putnbr_printf(n / 10, counter);
		ft_putnbr_printf(n % 10, counter);
	}
}
