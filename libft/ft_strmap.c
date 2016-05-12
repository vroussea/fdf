/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 13:03:23 by vroussea          #+#    #+#             */
/*   Updated: 2015/12/04 15:27:36 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*strn;
	unsigned int	idx;

	idx = 0;
	if ((strn = ft_strnew(ft_strlen(s))))
	{
		while (s[idx])
		{
			strn[idx] = f(s[idx]);
			idx++;
		}
	}
	else
		strn = NULL;
	return (strn);
}
