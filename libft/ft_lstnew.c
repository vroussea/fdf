/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:52:15 by vroussea          #+#    #+#             */
/*   Updated: 2015/12/15 21:55:14 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_link;

	if (!(new_link = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!(new_link->content = ft_memalloc(content_size)))
		return (NULL);
	if (content == NULL)
	{
		new_link->content = NULL;
		new_link->content_size = 0;
	}
	else
	{
		new_link->content_size = content_size;
		ft_memcpy(new_link->content, content, content_size);
	}
	new_link->next = NULL;
	return (new_link);
}
