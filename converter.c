/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 18:01:29 by vroussea          #+#    #+#             */
/*   Updated: 2016/04/05 19:58:57 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_pt	para_convert(int x, int y, int z, t_img *img)
{
	t_pt	pt;

	pt.y = y * img->sbpy + 100 - CST * z / 2 * 0.5 - 0.1 * x;
	pt.x = x * img->sbpx + 100 - CST * z * 0.3;
	return (pt);
}

void		para_caller(int **map, t_img *img)
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
			pt1 = para_convert(j - 1, i, map[i][j], img);
			pt2 = pt1;
			if (j + 1 <= map[i][0])
				pt2 = para_convert(j, i, map[i][j + 1], img);
			draw_line(pt1, pt2, img);
			if (map[i + 1])
				pt2 = para_convert(j - 1, i + 1, map[i + 1][j], img);
			draw_line(pt1, pt2, img);
			j++;
		}
		i++;
	}
}
