/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:29:29 by vroussea          #+#    #+#             */
/*   Updated: 2015/12/04 22:19:19 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if ((str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
	}
	else
		str = NULL;
	return (str);
}
