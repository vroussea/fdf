/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 18:01:29 by vroussea          #+#    #+#             */
/*   Updated: 2016/05/11 22:52:17 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>

static void	text(t_env env)
{
	mlx_string_put(env.mlx, env.win, 15, 5, 0xFFBBBB, "Rotations :");
	mlx_string_put(env.mlx, env.win, 15, 25, 0xFFBBBB, "7 - 9 : Z-axis");
	mlx_string_put(env.mlx, env.win, 15, 45, 0xFFBBBB, "8 - 5 : X-axis");
	mlx_string_put(env.mlx, env.win, 15, 65, 0xFFBBBB, "4 - 6 : Y-axis");
	mlx_string_put(env.mlx, env.win, env.sx - 220, 5, 0xFFBBBB,
					"Translations :");
	mlx_string_put(env.mlx, env.win, env.sx - 220, 25, 0xFFBBBB,
					"up - down : X-axis");
	mlx_string_put(env.mlx, env.win, env.sx - 220, 45, 0xFFBBBB,
					"left - right : Y-axis");
	mlx_string_put(env.mlx, env.win, env.sx - 190, env.sy - 35, 0xFFBBBB,
					"Escape to quit FdF");
	mlx_string_put(env.mlx, env.win, 15, env.sy - 75, 0xFFBBBB, "Zoom :");
	mlx_string_put(env.mlx, env.win, 15, env.sy - 55, 0xFFBBBB, "+ : more");
	mlx_string_put(env.mlx, env.win, 15, env.sy - 35, 0xFFBBBB, "- : less");
}

static void	color(int *col, int z, t_env env, int i)
{
	if (z > env.color[i][0])
	{
		*col = env.color[i][1];
		if (i < 4)
			color(col, z, env, (i + 1));
	}
}

static t_pt	para(int x, int y, int z, t_env env)
{
	t_pt	pt;

	if (z <= 0)
		pt.col = 0x000000AA;
	else
		color(&(pt.col), z, env, 0);
	z *= env.alt * env.zm;
	x *= env.zm;
	y *= env.zm;
	pt.x = (double)(env.mtx[0][0] * x + env.mtx[0][1] * y + env.mtx[0][2] * z);
	pt.y = (double)(env.mtx[1][0] * x + env.mtx[1][1] * y + env.mtx[1][2] * z);
	pt.z = (double)(env.mtx[2][0] * x + env.mtx[2][1] * y + env.mtx[2][2] * z);
	pt.x = pt.x - (double)(CST * pt.z) + env.tx;
	pt.y = pt.y - (double)(CST * pt.z / 2) + env.ty;
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
	int		i;
	int		j;

	if (!(env.meml = mlx_get_data_addr(env.img, &bpp, &(env.sizel), &edan))
		|| !(para_caller(map, env)))
		return (0);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 1, 1);
	text(env);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			env.mtx[i][j] = (i == j ? 1 : 0);
			j++;
		}
		i++;
	}
	ft_bzero(env.meml, env.sizel * env.sy);
	return (1);
}
