/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:18:39 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/23 15:47:47 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	iter(unsigned int i, char *c)
{
	static int		indexArray[11] = {0};
	unsigned int	i;
	int				i;

	if (i > 10 || indexArray[i] == 1)
		printf("wrong index\n");
	else
		indexArray[i] = 1;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
	else if (*c >= 'A' && *c <= 'Z')
		*c = *c + 32;
} */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int	main(void)
{
	char *str = "Lorem Ipsum";
	ft_striteri(NULL, &iter);
	printf("%s", str);
} */