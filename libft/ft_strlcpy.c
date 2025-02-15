/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:58:49 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/12 14:24:29 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

// cc -Wall -Wextra -Werror -lbsd ft_strlcpy.c && ./a.out
/*int	main(void)
{
	char src[] = "lorem ipsum";
	char srcs[] = "lorem ipsum";
	char dest[20];
	char dests[20];
	size_t size = 3;

	printf("dest : %s \nand the length : %zu\n\n", dest, strlcpy(dest, src,
			size));
	printf("dest : %s \nand the length : %zu\n\n", dests, ft_strlcpy(dests,
			srcs, size));
} */