/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 17:00:58 by vroussea          #+#    #+#             */
/*   Updated: 2016/03/24 19:41:13 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	nb_pts(int	**map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = j + map[i][0];
		i++; 
	}
	return (j);
}

void		para_convert(int **map)
{
	int	pts;

	pts = nb_pts(map);
	
}

/*void		iso_convert(int **map)
{
	int	**tab;


}*/
