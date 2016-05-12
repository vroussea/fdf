/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 22:17:44 by vroussea          #+#    #+#             */
/*   Updated: 2016/04/26 20:24:07 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(void ***tab)
{
	int		i;
	void	**ptr;

	i = 0;
	if (*tab)
	{
		ptr = *tab;
		while (ptr[i] != NULL)
		{
			ft_memdel(&ptr[i]);
			i++;
		}
		ft_memdel(ptr);
		*tab = NULL;
	}
}
