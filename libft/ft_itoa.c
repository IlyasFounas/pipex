/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:51:27 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/23 16:00:30 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_int_min(char *str, char *res, int n)
{
	int	i;

	i = 0;
	i = ft_strlen(str);
	res[i] = '\0';
	while (n <= -1)
	{
		res[--i] = (n % 10 * -1) + 48;
		n /= 10;
	}
	res[--i] = '-';
	return (res);
}

static char	*ft_charnbr(int n, int size, char *res)
{
	if (n == -2147483648)
	{
		res = ft_int_min("-2147483648", res, n);
		return (res);
	}
	if (n < 0)
	{
		size++;
		res[size] = '-';
		n *= -1;
	}
	if (n >= 0 && n <= 9)
	{
		size++;
		res[size] = (n + '0');
		res[size + 1] = '\0';
	}
	if (n > 9)
	{
		ft_charnbr(n / 10, size, res);
		ft_charnbr(n % 10, ft_strlen(res) - 1, res);
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		n_cpy;

	i = 0;
	if (n == 0)
		i++;
	n_cpy = n;
	if (n_cpy < 0)
	{
		if (n_cpy == -2147483648)
			n_cpy++;
		n_cpy *= -1;
		i++;
	}
	while (n_cpy >= 1)
	{
		n_cpy /= 10;
		i++;
	}
	res = malloc((i + 1) * sizeof(char));
	if (res == NULL)
		return (0);
	res = ft_charnbr(n, -1, res);
	return (res);
}
/*
int	main(void)
{
	printf("%s", ft_itoa(NULL));
}
*/