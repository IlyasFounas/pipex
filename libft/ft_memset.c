/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:40:22 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/20 16:20:27 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*s2;

	i = 0;
	s2 = (unsigned char *)s;
	while (i < n)
	{
		s2[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char	strs[] = "testt";
	char	strs2[] = "testt";

	// int i;
	// int strs[] = {2, 1, 2, 3, 2};
	// int strs2[] = {2, 1, 2, 3, 2};
	ft_memset(strs, 'c', 5);
	memset(strs2, 'c', 5);
	printf("ft_memset \n%s ", strs);
	printf("\nmemset \n%s ", strs2);
	i = -1;
	printf("ft_memset array : ");
	while (++i < 5)
		printf("%d ", strs[i]);
	i = -1;
	printf("\nmemset array    : ");
	while (++i < 5)
		printf("%d ", strs2[i]);
}
 */