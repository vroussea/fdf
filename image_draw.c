/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:05:09 by vroussea          #+#    #+#             */
/*   Updated: 2016/04/11 19:56:28 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** col : 2 = red, 1 = green, 0 = blue
*/

static void	color_pixel(int x, int y, t_env env, int col)
{
	if (x > 0 && x < env.sizel && x < env.sx && y > 0 && y < env.sy)
		env.meml[((x - 1) * 4 + (y - 1) * env.sizel + col)] = 0xFF;
}

void		line(t_pt pt1, t_pt pt2, t_env env)
{
	double	a;
	t_pt	pt;

	(pt1.x > pt2.x ? ft_intswap(&pt1.y, &pt2.y) : (void)0);
	(pt1.x > pt2.x ? ft_intswap(&pt1.x, &pt2.x) : (void)0);
	pt.x = 0;
	pt.y = 0;
	a = (double)(pt2.y - pt1.y) / (double)(pt2.x - pt1.x);
	if (a < 1 && a > -1)
		while (pt1.x + pt.x < pt2.x)
		{
			color_pixel(pt1.x + pt.x, pt1.y + pt.y, env, 2);
			pt.x++;
			pt.y = pt.x * a;
		}
	else
		while (pt1.y + pt.y != pt2.y)
		{
			color_pixel(pt1.x + pt.x, pt1.y + pt.y, env, 2);
			pt.y = (pt1.y < pt2.y ? pt.y + 1 : pt.y - 1);
			pt.x = pt.y / a;
		}
	color_pixel(pt1.x + pt.x, pt1.y + pt.y, env, 2);
}
