/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 18:01:29 by vroussea          #+#    #+#             */
/*   Updated: 2016/04/05 22:57:04 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

static t_pt	para_convert(int x, int y, int z, t_img *img)
{
	t_pt	pt;

	pt.y = y + y * img->sbpy + 100 - CST * z / 2 * 0.4 - 0.1 * x;
	pt.x = x + x * img->sbpx + 100 - CST * z * 0.4;
	if (x == 1 && y ==1 )
	{
		ft_putstr("pt.x : ");
		ft_putendl(ft_itoa(pt.x));
		ft_putstr("pt.y : ");
		ft_putendl(ft_itoa(pt.y));
	}
	return (pt);
}

static void		para_caller(int **map, t_img *img)
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

int			put_image(int **map, t_img *img)
{
	int		bpp;
	int 	edan;
	t_env	*env;

	env = img->env;
	if (!(img->ptr = mlx_new_image(env->mlx, env->szx, env->szy)))
		return (0);
	if (!(img->meml = mlx_get_data_addr(img->ptr, &bpp, &(img->sizel), &edan)))
		return (0);
	para_caller(map, img);
	mlx_put_image_to_window(env->mlx, env->win, img->ptr, 1, 1);
	mlx_destroy_image(env->mlx, img->ptr);
	return (1);
}
