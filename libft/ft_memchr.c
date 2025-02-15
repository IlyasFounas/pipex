/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:46:25 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/12 14:22:07 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned int	i;

	i = 0;
	s2 = (unsigned char *)s;
	while (i < n)
	{
		if (s2[i] == (unsigned char)c)
			return (s2 + i);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	unsigned char	*s;
	unsigned int	i;
	char			c[] = "the answer is : 42 !";
	unsigned char	*s2;
	char			cc[] = "the answer is : 42 !";

	i = 52;
	s = (unsigned char *)memchr(c + 15, i, 4);
	s2 = (unsigned char *)memchr(cc + 15, i, 4);
	printf("%s", s);
	printf("%s", s2);
}
*/