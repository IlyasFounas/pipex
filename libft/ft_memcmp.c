/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:37:33 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/13 09:44:45 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n <= 0)
		return (0);
	while (str[i] == str2[i] && i < n - 1)
		i++;
	if (i == n)
		return (str[i - 1] - str2[i - 1]);
	return (str[i] - str2[i]);
}
/*
int	main(void)
{
	char big[] = "";
	char little[] = "Gojo";
	char big2[] = "";
	char little2[] = "Gojo";

	printf("res : %d\n", memcmp(big, little, 4));

	printf("res : %d\n", ft_memcmp(big2, little2, 4));
} */