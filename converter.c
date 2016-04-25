/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 18:01:29 by vroussea          #+#    #+#             */
/*   Updated: 2016/04/25 19:30:54 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>

static t_pt	para(int x, int y, int z, t_env env)
{
	t_pt	pt;

	pt.x = (double)(env.mtx[0][0] * x + env.mtx[0][1] * y + env.mtx[0][2] * z + env.mtx[0][3]);
	pt.y = (double)(env.mtx[1][0] * x + env.mtx[1][1] * y + env.mtx[1][2] * z + env.mtx[1][3]);
	pt.z = (double)(env.mtx[2][0] * x + env.mtx[2][1] * y + env.mtx[2][2] * z + env.mtx[2][3]);
	pt.x = pt.x * env.px - CST * pt.z;
	pt.y = pt.y * env.py - CST * pt.z / 2;
//	pt.y = y * env.py * env.oy + env.dy - CST * z / 2 * 0.4 - 0.1 * env.px * x;
//	pt.x = x * env.px * env.ox + env.dx - CST * z * 0.4;
	return (pt);
}

static int	para_caller(int **map, t_env env)
{
	t_pt	pt1;
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 1;
		while (j <= map[i][0])
		{
			pt1 = para(j - 1, i, map[i][j], env);
			if (j + 1 <= map[i][0])
				line(pt1, para(j, i, map[i][j + 1], env), env);
			if (map[i + 1])
				line(pt1, para(j - 1, i + 1, map[i + 1][j], env), env);
			j++;
		}
		i++;
	}
	return (1);
}

int			put_image(int **map, t_env env)
{
	int		bpp;
	int		edan;

	if (!(env.img = mlx_new_image(env.mlx, env.sx, env.sy)) ||
		!(env.meml = mlx_get_data_addr(env.img, &bpp, &(env.sizel), &edan))
		|| !(para_caller(map, env)))
		return (0);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 1, 1);
	mlx_destroy_image(env.mlx, env.img);
	return (1);
}
