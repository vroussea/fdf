/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 20:12:26 by vroussea          #+#    #+#             */
/*   Updated: 2015/12/15 22:38:19 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*new_lst;
	t_list	*node;

	node = lst;
	new = (*f)(node);
	new_lst = new;
	while (node->next)
	{
		node = node->next;
		new->next = (*f)(node);
		new = new->next;
	}
	return (new_lst);
}
