/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:48:09 by ifounas           #+#    #+#             */
/*   Updated: 2024/11/20 14:53:17 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (del == NULL)
		return ;
	ptr = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		ft_lstdelone(ptr, del);
		ptr = *lst;
	}
	*lst = NULL;
}
