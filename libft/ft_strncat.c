/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:38:13 by vroussea          #+#    #+#             */
/*   Updated: 2015/12/23 17:13:07 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = s1;
	tmp2 = (char *)s2;
	if (n && *tmp2)
	{
		while (*tmp1 != '\0')
			tmp1++;
		while (n && *tmp2)
		{
			*tmp1 = *tmp2;
			tmp2++;
			tmp1++;
			n--;
		}
		if (*tmp1 != '\0')
			*tmp1 = '\0';
	}
	return (s1);
}
