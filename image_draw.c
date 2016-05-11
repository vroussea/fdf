/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:05:09 by vroussea          #+#    #+#             */
/*   Updated: 2016/05/11 21:49:14 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	color_pixel(int x, int y, t_env env, int col)
{
	if (x > 0 && x < env.sizel && x < env.sx && y > 0 && y < env.sy)
		ft_memcpy(&env.meml[(x - 1) * 4 + (y - 1) * env.sizel], &col, 4);
}

static int	color(t_pt pt1, t_pt pt2, t_pt pt)
{
	double			diff;
	unsigned char	*p1;
	unsigned char	*p2;
	unsigned char	*p;
	int				res;

	if (pt1.col == pt2.col)
		return (pt2.col);
	diff = (ft_abs((pt2.x - pt1.x)) > ft_abs((pt2.y - pt1.y)) ?
			(double)(pt.x / (double)(pt2.x - pt1.x)) :
			(double)(pt.y / (double)(pt2.y - pt1.y)));
	p = (unsigned char *)&res;
	p1 = (unsigned char *)&pt2.col;
	p2 = (unsigned char *)&pt1.col;
	p[0] = (p2[0] > p1[0] ? p1[0] + ft_abs(p1[0] - p2[0]) * (1 - diff) :
			p2[0] + ft_abs(p1[0] - p2[0]) * diff);
	p[1] = (p2[1] > p1[1] ? p1[1] + ft_abs(p1[1] - p2[1]) * (1 - diff) :
			p2[1] + ft_abs(p1[1] - p2[1]) * diff);
	p[2] = (p2[2] > p1[2] ? p1[2] + ft_abs(p1[2] - p2[2]) * (1 - diff) :
			p2[2] + ft_abs(p1[2] - p2[2]) * diff);
	p[3] = (p2[3] > p1[3] ? p1[3] + ft_abs(p1[3] - p2[3]) * (1 - diff) :
			p2[3] + ft_abs(p1[3] - p2[3]) * diff);
	return (res);
}

static void	x_dir(t_pt pt1, t_pt pt2, double a, t_env env)
{
	t_pt	pt;

	pt.x = 0;
	pt.y = 0;
	while (pt1.x + pt.x < pt2.x)
	{
		color_pixel(pt1.x + pt.x, pt1.y + pt.y, env, color(pt1, pt2, pt));
		pt.x++;
		pt.y = pt.x * a;
	}
	color_pixel(pt1.x + pt.x, pt1.y + pt.y, env, color(pt1, pt2, pt));
}

static void	y_dir(t_pt pt1, t_pt pt2, double a, t_env env)
{
	int		dir;
	t_pt	pt;

	pt.x = 0;
	pt.y = 0;
	dir = (pt1.y < pt2.y ? 1 : -1);
	while (pt1.y + pt.y != pt2.y)
	{
		color_pixel(pt1.x + pt.x, pt1.y + pt.y, env, color(pt1, pt2, pt));
		pt.y += dir;
		pt.x = pt.y / a;
	}
	color_pixel(pt1.x + pt.x, pt1.y + pt.y, env, color(pt1, pt2, pt));
}

void		line(t_pt pt1, t_pt pt2, t_env env)
{
	double	a;

	if ((pt1.x > env.sx && pt2.x > env.sx) || (pt1.x < 0 && pt2.x < 0) ||
			(pt1.y > env.sy && pt2.y > env.sy) || (pt1.y < 0 && pt2.y < 0))
		return ;
	if (pt1.x > pt2.x)
	{
		ft_intswap(&(pt1.col), &(pt2.col));
		ft_intswap(&(pt1.y), &(pt2.y));
		ft_intswap(&(pt1.x), &(pt2.x));
	}
	a = (double)(pt2.y - pt1.y) / (double)(pt2.x - pt1.x);
	if (a < 1 && a > -1)
		x_dir(pt1, pt2, a, env);
	else
		y_dir(pt1, pt2, a, env);
}
