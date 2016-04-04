/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 17:00:58 by vroussea          #+#    #+#             */
/*   Updated: 2016/04/04 16:48:17 by vroussea         ###   ########.fr       */
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

	pt.y = y * 30 + 1 * SIZE_Y / 4 - CST * z / 2 * 6 - 4 * x;
	pt.x = x * 40 + SIZE_X / 5 - CST * z * 4;
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

/*void		iso_convert(int **map)
{
	int	**tab;


}*/
