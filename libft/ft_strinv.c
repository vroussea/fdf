/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:44:49 by vroussea          #+#    #+#             */
/*   Updated: 2015/11/28 19:15:32 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strinv(char *s)
{
	char	*tmp;
	size_t	size_tmp;
	size_t	size_s;

	size_tmp = 0;
	size_s = ft_strlen(s);
	tmp = ft_strnew(size_s);
	while (size_s)
	{
		size_s--;
		tmp[size_tmp] = s[size_s];
		size_tmp++;
	}
	tmp[size_tmp] = '\0';
	return (tmp);
}
