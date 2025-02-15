/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:45:52 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/15 08:20:45 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;

	len_dest = ft_strlen(dst);
	i = 0;
	if (size <= len_dest)
	{
		return (ft_strlen(src) + size);
	}
	if (size > 0)
	{
		while (src[i] && i < size - 1 - len_dest)
		{
			dst[len_dest + i] = src[i];
			i++;
		}
		dst[len_dest + i] = '\0';
	}
	return (ft_strlen(src) + len_dest);
}
/*
int	main(void)
{
	char dest[40] = "truc";
	char dests[40] = "truc";
	char src[] = "lorem ipsum dolor sit amet";
	char srcs[] = "lorem ipsum dolor sit amet";

	//dest[8] = 'a';
	//dests[8] = 'a';
	size_t size = 13;
	printf("dest : %s \nand the length : %zu\n\n", dest, strlcat(dest, src,
			size));
	printf("dest : %s \nand the length : %zu\n\n", dests, ft_strlcat(dests,
			srcs, size));
} */