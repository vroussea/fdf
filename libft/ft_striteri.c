/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 12:48:56 by vroussea          #+#    #+#             */
/*   Updated: 2015/12/04 13:00:10 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	idx;
	char			*tmp;

	tmp = s;
	idx = 0;
	while (*tmp)
	{
		f(idx, tmp);
		idx++;
		tmp++;
	}
}
