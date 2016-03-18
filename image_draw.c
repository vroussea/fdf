/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:05:09 by vroussea          #+#    #+#             */
/*   Updated: 2016/03/18 21:10:46 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	color_pixel_red(int x, int y, char *memloc, int size_line)
{
	memloc[((x - 1) * 4 + (y - 1) * size_line + 2)] = 0xFF;
}

/*static void	color_pixel_green(int x, int y, char *memloc, int size_line)
{
	memloc[((x - 1) * 4 + (y - 1) * size_line + 1)] = 0xFF;
}

static void	color_pixel_blue(int x, int y, char *memloc, int size_line)
{
	memloc[((x - 1) * 4 + (y - 1) * size_line)] = 0xFF;
}*/

void		draw_line(int x1, int y1, int x2, int y2, int size_line, char *memloc)
{
	double	a;

	if (x1 > x2)
	{
		ft_intswap(&x1, &x2);
		ft_intswap(&y1, &y2);
	}
	a = (double)((y2 - y1) / (x2 - x1));
	if (a < -1 || a > 1)
		while (x1 <= x2)
		{
			x1++;
			y1 = x1 * a;
			color_pixel_red(x1, y1, memloc, size_line);
		}
	else
	{
		if (y1 < y2)
			while (y1 <= y2)
			{
				y1++;
				x1 = y1 / a;
				color_pixel_red(x1, y1, memloc, size_line);
			}
		else
			while (y1 >= y2)
			{
				y1--;
				x1 = x1 / a;
				color_pixel_red(x1, y1, memloc, size_line);
			}
	}
}
