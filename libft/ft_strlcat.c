/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:51:33 by vroussea          #+#    #+#             */
/*   Updated: 2015/12/16 20:18:06 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_sizetest(char *dst, size_t size)
{
	int	idx;

	idx = 0;
	while (dst[idx] && size)
	{
		idx++;
		size--;
	}
	return (size);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*tmpd;
	int		cpt;
	size_t	vmax;
	size_t	tmpsize;

	tmpsize = size;
	tmpd = dst;
	vmax = ft_strlen(dst);
	size = ft_sizetest(dst, size);
	while (*tmpd)
		tmpd++;
	if (size == 0)
		return (tmpsize + ft_strlen(src));
	cpt = 0;
	while (src[cpt] && size - 1)
	{
		*tmpd = src[cpt];
		size--;
		cpt++;
		tmpd++;
	}
	if (size && src[cpt] == '\0')
		*tmpd = '\0';
	return (ft_strlen(src) + vmax);
}
