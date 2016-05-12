/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:02:34 by vroussea          #+#    #+#             */
/*   Updated: 2015/12/08 18:36:16 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_itod(char *str, unsigned int n, size_t size)
{
	str[size] = '\0';
	size--;
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[size] = '0' + (n % 10);
		n = n / 10;
		size--;
	}
}

static size_t	ft_sizestr(unsigned int n)
{
	if (n > 9)
		return (1 + ft_sizestr(n / 10));
	return (1);
}

char			*ft_itoa(int n)
{
	size_t			size;
	int				if_neg;
	char			*str;
	unsigned int	value;

	if_neg = 0;
	if (n < 0)
	{
		if_neg++;
		value = n * -1;
	}
	else
		value = n;
	size = ft_sizestr(value);
	if (!(str = ft_strnew(size + if_neg)))
		return (NULL);
	ft_itod(str, value, (size + if_neg));
	if (if_neg)
		str[0] = '-';
	return (str);
}
