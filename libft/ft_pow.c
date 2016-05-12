/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:18:01 by vroussea          #+#    #+#             */
/*   Updated: 2015/12/23 17:10:09 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow(double x, double y)
{
	int	value;
	int	yneg;

	value = x;
	yneg = 0;
	if (y == 0)
		return (1);
	if (y < 0)
	{
		y = y * -1;
		yneg++;
	}
	while (y > 1)
	{
		x = x * value;
		y--;
	}
	if (yneg)
		return (1 / x);
	return (x);
}
