/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:05:09 by vroussea          #+#    #+#             */
/*   Updated: 2016/03/22 15:35:09 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** col : 2 = red, 1 = green, 0 = blue
*/

static void	color_pixel(int x, int y, char *memloc, int size_line, int col)
{
	memloc[((x - 1) * 4 + (y - 1) * size_line + col)] = 0xFF;
}

void		draw_line(int x1, int y1, int x2, int y2, int size_line, char *memloc)
{
	double	a;
	int		x;
	int		y;

	(x1 > x2 ? ft_intswap(&y1, &y2) : (void)0);
	(x1 > x2 ? ft_intswap(&x1, &x2) : (void)0);
	x = 0;
	y = 0;
	a = (double)(y2 - y1) / (double)(x2 - x1);
	if (a < 1 && a > -1)
		while (x1 + x < x2)
		{
			color_pixel(x1 + x, y1 + y, memloc, size_line, 2);
			x++;
			y = x * a;
		}
	else
		while (y1 + y != y2)
		{
			color_pixel(x1 + x, y1 + y, memloc, size_line, 2);
			y = (y1 < y2 ? y + 1 : y - 1);
			x = y / a;
		}
	color_pixel(x1 + x, y1 + y, memloc, size_line, 2);
}
