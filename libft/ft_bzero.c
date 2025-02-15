/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:45:19 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/20 16:08:02 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	unsigned char	*s2;

	i = 0;
	s2 = (unsigned char *)s;
	while (i < n)
	{
		s2[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	//char strs[] = "bienvenue a 42";
	//char strs2[] = "bienvenue a 42";

	int i;
	//int strs[] = {2, 1, 2, 3, 2};
	//int strs2[] = {2, 1, 2, 3, 2};
	int strs[] = {};
	int strs2[] = {};
	ft_bzero(strs, 5);
	bzero(strs2, 5);
	//printf("%s ", strs);
	//printf("%s ", strs2);
	i = -1;
	printf("ft_bzero array : ");
	while (++i < 5)
		printf("%d ", strs[i]);
	i = -1;
	printf("\nbzero array    : ");
	while (++i < 5)
		printf("%d ", strs2[i]);
} */