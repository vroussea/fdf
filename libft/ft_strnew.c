/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:20:54 by vroussea          #+#    #+#             */
/*   Updated: 2015/12/03 16:36:02 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_str;

	new_str = NULL;
	if ((new_str = (char *)ft_memalloc((size + 1))))
	{
		ft_bzero(new_str, size + 1);
		return (new_str);
	}
	else
		return (NULL);
}
