/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:05:21 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/20 14:59:48 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*void	*ft_map(void *ct)
{
	int i;
	void	*c;
	char	*pouet;

	c = ct;
	i = -1;
	pouet = (char *)c;
	while (pouet[++i])
		if (pouet[i] == 'o')
			pouet[i] = 'a';
	return (c);
}

void    ft_del(void *content)
{
	free(content);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new_list;
	void	*ptr_tof;

	new_list = NULL;
	while (lst)
	{
		ptr_tof = f(lst->content);
		if (ptr_tof == NULL)
		{
			ft_lstclear(&new_list, del);
			return (0);
		}
		ptr = ft_lstnew(ptr_tof);
		if (ptr == NULL)
		{
			ft_lstclear(&new_list, del);
			del(ptr_tof);
			return (0);
		}
		ft_lstadd_back(&new_list, ptr);
		lst = lst->next;
	}
	return (new_list);
}
/*
int main(void)
{
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	t_list		*list;

	char str1[] = "lorem";
	char str2[] = "ipsum";
	char str3[] = "dolor";
	char str4[] = "sit";
	elem = ft_lstnew(str1);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);
	elem->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	list = ft_lstmap(elem, &ft_map, &ft_del);
	while (list)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	} 
	//ft_lstclear(&elem, ft_del);
	return (0);
}
*/