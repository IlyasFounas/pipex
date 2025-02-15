/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:03:32 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/21 15:10:11 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
/*
int	main(void)
{
	int		i;

	i = 97;
	while (i <= 122)
	{
		printf("%c", i);
		printf("%c\n", toupper(i));
		i++;
	}
	//printf("\n%c", ft_toupper(97));
} */