/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:01:38 by vroussea          #+#    #+#             */
/*   Updated: 2015/12/08 17:48:07 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	value;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		value = n * -1;
	}
	else
		value = n;
	if (value > 9)
	{
		ft_putnbr_fd(value / 10, fd);
		ft_putnbr_fd(value % 10, fd);
	}
	else
		ft_putchar_fd('0' + value, fd);
}
