/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 11:49:16 by vroussea          #+#    #+#             */
/*   Updated: 2015/12/04 15:17:05 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	size_s1;
	size_t	cpt;
	size_t	cpt2;
	size_t	cpt3;
	char	*loc;

	size_s1 = ft_strlen(s1);
	cpt = 0;
	loc = (char *)s1;
	if (s2[cpt] == '\0')
		return (loc);
	while (cpt <= size_s1)
	{
		cpt2 = cpt;
		cpt3 = 0;
		while (s1[cpt2] == s2[cpt3] && s1[cpt2] != '\0')
		{
			cpt3++;
			if (s2[cpt3] == '\0')
				return ((loc + cpt));
			cpt2++;
		}
		cpt++;
	}
	return (NULL);
}
