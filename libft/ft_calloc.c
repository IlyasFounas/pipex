/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:32:52 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/21 13:24:56 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size == 0 || nmemb == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	if (nmemb > SIZE_MAX / size || size > SIZE_MAX / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
int	main(void)
{
	size_t n;
	size_t i;
	size_t *ptr;
	size_t *ptr2;

	n = 10;
	i = 0;
	ptr = calloc(n, sizeof(size_t));
	ptr2 = ft_calloc(n, sizeof(size_t));
	if (ptr == NULL)
		exit(0);
	if (ptr2 == NULL)
		exit(0);
	printf("calloc | ft_calloc\n");
	while (++i < n)
	{
		printf("   %zu   ", ptr[i]);
		printf("|     %zu\n", ptr2[i]);
	}
	free(ptr);
	free(ptr2);
} */