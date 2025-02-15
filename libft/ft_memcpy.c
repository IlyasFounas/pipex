/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:54:09 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/12 14:22:43 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*src2;
	unsigned char	*dest2;

	i = 0;
	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char src[] = "test test1 test2";
	char srcs[] = "test test1 test2";
	char dest0[7];
	char dest1[7];


	memcpy(dest1, srcs + 5, 5);
	ft_memcpy(dest0, src + 5, 5);
	printf("memcpy : \n%s", dest1);
	printf("\n\nft_memcpy : \n%s", dest0);

} */