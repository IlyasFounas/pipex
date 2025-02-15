/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:13:13 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/11 16:23:01 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	mark;

	i = 0;
	mark = 0;
	c = (char)c;
	while (s[i])
	{
		if (s[i] == c)
			mark = i;
		i++;
	}
	if (s[i] == c && s[i] == '\0')
		return (&*(char *)(s + i));
	else if (mark > 0 || s[mark] == c)
		return (&*(char *)(s + mark));
	return (NULL);
}
/*
int	main(void)
{
	char	s[] = "bonjour";
	char	ss[] = "bonjour";
	int		c;

	// char	s[] = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
	// char	ss[] = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
	c = 'b';
	printf("\n%s\n", strrchr(s, c));
	printf("\n%s", ft_strrchr(ss, c));
}
*/