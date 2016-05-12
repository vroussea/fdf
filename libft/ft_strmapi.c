/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:39:09 by vroussea          #+#    #+#             */
/*   Updated: 2015/12/09 12:53:20 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*strn;
	unsigned int	idx;

	idx = 0;
	if ((strn = ft_strnew(ft_strlen(s))))
	{
		while (s[idx])
		{
			strn[idx] = f(idx, s[idx]);
			idx++;
		}
	}
	else
		strn = NULL;
	return (strn);
}
