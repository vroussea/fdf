/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 20:12:12 by vroussea          #+#    #+#             */
/*   Updated: 2016/05/02 22:47:57 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	**ft_matrixid(int size)
{
	double	**mat;
	int		i;
	int		j;

	i = 0;
	if (!(mat = (double **)ft_memalloc(sizeof(double *) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(mat[i] = (double *)ft_memalloc(sizeof(double) * size)))
			return (NULL);
		i++;
	}
	mat[i] = NULL;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j++ < size)
			mat[i][j - 1] = (i == j - 1 ? 1 : 0);
		i++;
	}
	return (mat);
}
