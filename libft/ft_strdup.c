/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:23:08 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/23 15:51:05 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cc;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	i = 0;
	cc = malloc(s_len + 1);
	if (cc == NULL)
		return (0);
	while (i < s_len)
	{
		cc[i] = s[i];
		i++;
	}
	cc[i] = '\0';
	return (cc);
}
/*
int	main(void)
{
	// char str[] = "lorem ipsum dolor sit amet";
	char *str = NULL;
	char *strccpy;
	//char *strccpy2;

	strccpy = strdup(str);
	//strccpy2 = ft_strdup(str);
	// printf("strdup : \noriginal : %s \ncopy     : %s", str, strccpy);
	// printf("\n\nft_strdup : \noriginal : %s \ncopy     : %s", str, strccpy2);
} */