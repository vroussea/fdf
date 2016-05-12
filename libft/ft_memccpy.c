/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:38:05 by vroussea          #+#    #+#             */
/*   Updated: 2015/11/28 19:46:59 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (tmp[i] == (unsigned char)c)
		{
			ft_memcpy(dst, src, i + 1);
			return (dst + i + 1);
		}
		i++;
	}
	ft_memcpy(dst, src, n);
	return (NULL);
}
