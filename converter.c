/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 18:01:29 by vroussea          #+#    #+#             */
/*   Updated: 2016/04/08 18:27:35 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>

static t_pt	para(int x, int y, int z, t_img *img)
{
	t_pt	pt;

	pt.y = y + y * img->sbpy + 100 - CST * z / 2 * 0.4 - 0.1 * x;
	pt.x = x + x * img->sbpx + 100 - CST * z * 0.4;
	return (pt);
}

static int	para_caller(int **map, t_img *img)
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
			pt1 = para(j - 1, i, map[i][j], img);
			if (j + 1 <= map[i][0])
				line(pt1, para(j, i, map[i][j + 1], img), img);
			if (map[i + 1])
				line(pt1, para(j - 1, i + 1, map[i + 1][j], img), img);
			j++;
		}
		i++;
	}
	return (1);
}

int			put_image(int **map, t_img *img)
{
	int		bpp;
	int		edan;
	t_env	*env;

	env = img->env;
	if (!(img->ptr = mlx_new_image(env->mlx, env->szx, env->szy)) ||
		!(img->meml = mlx_get_data_addr(img->ptr, &bpp, &(img->sizel), &edan))
		|| !(para_caller(map, img)))
		return (0);
	mlx_put_image_to_window(env->mlx, env->win, img->ptr, 1, 1);
	mlx_destroy_image(env->mlx, img->ptr);
	return (1);
}
