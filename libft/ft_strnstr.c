/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:20:34 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/12 16:31:48 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		while (i + j < len && big[i + j] == little[j] && big[i + j]
			&& little[j])
			j++;
		if (j == ft_strlen(little))
			return (&*(char *)(big + (i)));
		j = 0;
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char big[] = "Mais où est donc CCharlie ?";
	const char little[] = "Charlie";
	char big2[] = "Mais où est donc CCharlie ?";
	char little2[] = "Charlie";
	size_t len;

	len = 34;

	printf("strnstr    : %s", strnstr(big, little, len));
	printf("\n\nft_strnstr : %s", ft_strnstr(big2, little2, len));
} */