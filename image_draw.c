/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:05:09 by vroussea          #+#    #+#             */
/*   Updated: 2016/04/08 18:28:43 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** col : 2 = red, 1 = green, 0 = blue
*/

static void	color_pixel(int x, int y, t_img *img, int col)
{
	if (x > 0 && x < img->sizel && x < img->env->szx
		&& y > 0 && y < img->env->szy)
		img->meml[((x - 1) * 4 + (y - 1) * img->sizel + col)] = 0xFF;
}

void		line(t_pt pt1, t_pt pt2, t_img *img)
{
	double	a;
	int		x;
	int		y;

	(pt1.x > pt2.x ? ft_intswap(&pt1.y, &pt2.y) : (void)0);
	(pt1.x > pt2.x ? ft_intswap(&pt1.x, &pt2.x) : (void)0);
	x = 0;
	y = 0;
	a = (double)(pt2.y - pt1.y) / (double)(pt2.x - pt1.x);
	if (a < 1 && a > -1)
		while (pt1.x + x < pt2.x)
		{
			color_pixel(pt1.x + x, pt1.y + y, img, 2);
			x++;
			y = x * a;
		}
	else
		while (pt1.y + y != pt2.y)
		{
			color_pixel(pt1.x + x, pt1.y + y, img, 2);
			y = (pt1.y < pt2.y ? y + 1 : y - 1);
			x = y / a;
		}
	color_pixel(pt1.x + x, pt1.y + y, img, 2);
}
