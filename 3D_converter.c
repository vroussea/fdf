/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 17:00:58 by vroussea          #+#    #+#             */
/*   Updated: 2016/04/04 21:32:56 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*static int	nb_pts(int	**map)
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
}*/

static t_pt	para_convert(int x, int y, int z)
{
	t_pt	pt;

	pt.y = y * 2 + 100 - CST * z / 2 * 0.5  - 0.1 * x;
	pt.x = x * 2 + 100 - CST * z * 0.3;
	return (pt);
}

void		para_caller(int **map, t_img img)
{
	t_pt	pt1;
	t_pt	pt2;
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 1;
		while (j <= map[i][0])
		{
			pt1 = para_convert(j - 1, i, map[i][j]);
			if (j + 1 <= map[i][0])
			{
				pt2 = para_convert(j, i, map[i][j + 1]);
				draw_line(pt1, pt2, img);
			}
			if (map[i + 1])
			{
				pt2 = para_convert(j - 1, i + 1, map[i + 1][j]);
				draw_line(pt1, pt2, img);
			}
			j++;
		}
		i++;
	}
}
