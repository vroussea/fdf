/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 23:10:29 by vroussea          #+#    #+#             */
/*   Updated: 2015/12/15 23:22:10 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int x)
{
	int	i;

	i = 2;
	if (x < 0)
		return (-1);
	if (x == 0 || x == 1)
		return (x);
	while ((i * i) <= x)
	{
		if ((i * i) == x)
			return (i);
		i++;
	}
	return (-1);
}
