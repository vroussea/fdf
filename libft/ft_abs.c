/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 18:33:10 by vroussea          #+#    #+#             */
/*   Updated: 2015/12/23 18:36:00 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_abs(int n)
{
	unsigned int	value;

	if (n < 0)
		value = (unsigned int)n * -1;
	else
		value = (unsigned int)n;
	return (value);
}
