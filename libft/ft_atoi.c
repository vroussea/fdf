/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:02:38 by vroussea          #+#    #+#             */
/*   Updated: 2015/12/05 14:20:53 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	size;
	int		val;
	int		neg;
	size_t	cpt;

	size = ft_strlen(str);
	val = 0;
	cpt = 0;
	neg = 1;
	while (ft_isspace(str[cpt]))
		cpt++;
	if (str[cpt] == '-')
	{
		neg = -neg;
		cpt++;
	}
	else if (str[cpt] == '+')
		cpt++;
	while (ft_isdigit(str[cpt]))
	{
		val = val * 10;
		val = (str[cpt] - '0') + val;
		cpt++;
	}
	return (val * neg);
}
