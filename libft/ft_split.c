/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:45:53 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/23 15:39:41 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (s[i] != c && s[i] != '\0')
		words++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			words++;
		i++;
	}
	return (words);
}

static char	**ft_free(char **dst, int i)
{
	while (--i >= 0)
		free(dst[i]);
	free(dst);
	return (0);
}

static char	*ft_tmp_word(char const *s, char c, size_t index)
{
	char	*tmp;
	size_t	k;
	size_t	f;

	k = 0;
	f = 0;
	while (s[index + f] && s[index + f] != c)
		f++;
	tmp = malloc((f + 1) * sizeof(char));
	if (tmp == NULL)
		return (0);
	while (s[index + k] != '\0' && s[index + k] != c)
	{
		tmp[k] = s[index + k];
		k++;
	}
	tmp[f] = '\0';
	return (tmp);
}

static size_t	ft_count_index(size_t index, const char *s, char c)
{
	while (s[index] && s[index] != c)
		index++;
	while (s[index] && s[index] == c)
		index++;
	if (s[index] == c)
		index++;
	return (index);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**dst;
	size_t	index;

	if (s == NULL)
		return (0);
	i = -1;
	index = 0;
	dst = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (dst == NULL)
		return (0);
	while (++i < (ft_count_words(s, c)))
	{
		if (s[index] == c && s[index] != '\0' && index == 0)
			index = ft_count_index(index, s, c);
		dst[i] = ft_tmp_word(s, c, index);
		if (dst[i] == NULL)
			return (ft_free(dst, i));
		index = ft_count_index(index, s, c);
		if (dst[i] == NULL)
			return (ft_free(dst, i));
	}
	dst[i] = NULL;
	return (dst);
}
/*
int	main(void)
{
	int i = -1;
	char *str = NULL;
	char c = '0';
	char **dst = ft_split(str, c);
	printf("%p", dst);
	
	while (++i < ft_count_words(str, c))
		printf("%s\n", dst[i]); 
	free(dst);
}*/