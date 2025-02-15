/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:03:36 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/20 14:55:52 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list *begin;
	t_list *elem;
	t_list *elem2;

	begin = NULL;
	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (0);
	elem->content = (void *)"lorem";
	elem->next = NULL;
	elem2 = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (0);
	elem2->content = (void *)"ipsum";
	elem2->next = NULL;
	ft_lstadd_front(&begin, elem);
	ft_lstadd_front(&begin, elem2);
	while (begin)
	{
		printf("%s", (char *)begin->content);
		begin = begin->next;
	}
	free(elem);
	free(elem2);
} */
