/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:20:26 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/20 16:21:39 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src2;
	unsigned char	*dest2;

	i = 0;
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest2 <= src2)
		ft_memcpy(dest2, src2, n);
	else
	{
		while (i < n)
		{
			n--;
			dest2[n] = src2[n];
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	str1[] = "lorem ipsum dolor sit amet";
	char	str2[] = "lorem ipsum dolor sit amet";

	printf("- memmove : \nInitial str1     : %s\n", str1);
	memmove(str1 + 1, str1, 8);
	printf("Transformed str1 : %s\n\n", str1);

	printf("||||||||||||||||||||||||||||||||\n\n");

	printf("- ft_memmove : \nInitial str2     : %s\n", str2);
	ft_memmove(str2 + 1, str2, 8);
	printf("Transformed str2 : %s\n\n", str2);
} */