/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:46:43 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/13 11:47:45 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	c = (char)c;
	while (*s && *s != c)
		s++;
	if (*s == c)
		return (&*(char *)s);
	return (NULL);
}
/*
int	main(void)
{
	char	scs[] = "karot";
	char	scss[] = "karot";
	int		c;

	c = 'd';
	printf("%s", strchr(scs, c));
	printf("\n%s", ft_strchr(scss, c));
} */