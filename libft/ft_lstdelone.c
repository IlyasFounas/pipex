/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:30:04 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/20 14:51:59 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del == NULL || lst == NULL)
		return ;
	del(lst->content);
	free(lst);
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
	ft_lstadd_back(&begin, elem);
	ft_lstadd_back(&begin, elem2);
	ft_lstdelone();
	while (begin)
	{
		printf("%s", (char *)begin->content);
		begin = begin->next;
	}
	free(elem);
	free(elem2);
} */