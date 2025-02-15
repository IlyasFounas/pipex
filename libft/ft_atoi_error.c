/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:27:55 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/12 14:51:34 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_or_isnt_negatif(char c, int *neg, int i)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			*neg = -1;
		i++;
	}
	return (i);
}

long int	ft_atoi_error(const char *nptr)
{
	int			i;
	int			neg;
	long int	nb;

	nb = 0;
	neg = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	i = is_or_isnt_negatif(nptr[i], &neg, i);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (nb > ((2147483647 - (nptr[i] - 48)) / 10))
			return (LONG_MIN + 1);
		if (-nb < (((-2147483649) + (nptr[i] - 48)) / 10))
			return (LONG_MIN + 1);
		nb = (nb * 10) + (nptr[i] - 48);
		i++;
	}
	if ((nptr[i] == '+' || nptr[i] == '-' || ft_isalpha(nptr[i]) == 1))
		return (LONG_MIN + 1);
	return (nb * neg);
}
