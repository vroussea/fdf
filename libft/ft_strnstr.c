/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:31:30 by vroussea          #+#    #+#             */
/*   Updated: 2015/12/04 15:18:05 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	size_s1;
	size_t	idx;
	size_t	idx2;
	size_t	idx3;
	char	*loc;

	size_s1 = ft_strlen(s1);
	idx = 0;
	loc = (char *)s1;
	if (s2[idx] == '\0')
		return (loc);
	while (idx < n && idx <= size_s1)
	{
		idx2 = idx;
		idx3 = 0;
		while (s1[idx2] == s2[idx3] && idx2 <= size_s1 && idx2 < n)
		{
			idx3++;
			if (s2[idx3] == '\0')
				return ((loc + idx));
			idx2++;
		}
		idx++;
	}
	return (NULL);
}
