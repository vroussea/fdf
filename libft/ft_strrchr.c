/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:35:43 by vroussea          #+#    #+#             */
/*   Updated: 2015/11/28 19:48:04 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;
	char	*tmp;

	tmp = (char *)s;
	size = ft_strlen(s);
	while (size)
	{
		if (tmp[size] == (unsigned char)c)
			return (&tmp[size]);
		size--;
	}
	if (tmp[size] == (unsigned char)c)
		return (&tmp[size]);
	return (NULL);
}
