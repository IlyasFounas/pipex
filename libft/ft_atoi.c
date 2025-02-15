/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:48:45 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/21 15:19:58 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	int			neg;
	long int	nb;

	nb = 0;
	neg = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -neg;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (nb > ((LONG_MAX - (nptr[i] - 48)) / 10))
			return (-1);
		if (-nb < ((LONG_MIN + (nptr[i] - 48)) / 10))
			return (0);
		nb = (nb * 10) + (nptr[i] - 48);
		i++;
	}
	return (nb * neg);
}
