/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:09:02 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/23 15:56:05 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;

	if (s1 == NULL || s2 == NULL)
		return (0);
	dst = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (dst == NULL)
		return (0);
	ft_strlcpy(dst, s1, ft_strlen(s1) + 1);
	ft_strlcat(dst, s2, ft_strlen(dst) + ft_strlen(s2) + 1);
	return (dst);
}
/*
int	main(void)
{
 	char *s1 = "my favorite animal is";
 	char *s2 = NULL;
 	char *s3 = "the nyancat";
 	char *dst = ft_strjoin(ft_strjoin(s1, s2), s3);


	printf("%s", dst);
} */
