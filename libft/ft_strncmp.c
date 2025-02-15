/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:20:39 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/12 14:24:44 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n <= 0)
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && i < n - 1 && s1[i]
		&& s2[i])
		i++;
	if (i == n)
		return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main(void)
{
	char c[] = "test\200";
	char cc[] = "test\0";

	printf("%d\n", strncmp(c, cc, 6));
	printf("%d", ft_strncmp(c, cc, 6));
} */