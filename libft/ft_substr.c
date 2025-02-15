/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:18:56 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/23 15:53:20 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	if (s == NULL)
		return (0);
	if ((size_t)start >= ft_strlen(s) && s != NULL)
	{
		dst = ft_calloc(1, sizeof(char));
		return (dst);
	}
	if (len >= ft_strlen(s + start))
		len = ft_strlen(s + start);
	dst = malloc(len + 1);
	if (dst == NULL)
		return (0);
	ft_strlcpy(dst, s + start, len + 1);
	return (dst);
}
/*
int	main(void)
{
	char *s = NULL;

	printf("%s \n", ft_substr(s, 0, 3));
} */
