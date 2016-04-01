/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:28:45 by vroussea          #+#    #+#             */
/*   Updated: 2016/04/01 22:31:25 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"

int	my_key_func(int keycode, void *param)
{
	int	tmp;

	tmp = (int)param;
	if (keycode == 53)
	{
		ft_putendl("Programme fermé");
		exit(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		**map;
	t_img   img;
	t_pt	pt1;
	t_pt	pt2;
	int		b_per_p;
	int		endian;
	int		x;
	int		y;
	int		i;
	int		j;

	map = NULL;
	if (argc == 2)
	{
		if (!file_reader(argv[1], &map))
		{
			ft_putendl("Error with map file or malloc !");
			return (0);
		}
		i = 0;
		while (map[i] != NULL)
		{
			j = 0;
			while (j < map[i][0] + 1)
			{
				ft_putnbr(map[i][j]);
				if (map[i][j] < 10)
					ft_putchar(' ');
				j++;
				ft_putchar(' ');
			}
			ft_putchar('\n');
			i++;
		}
		x = 1000;
		y = 1000;
		if (!(mlx = mlx_init()))
			return (0);
		win = mlx_new_window(mlx, SIZE_X, SIZE_Y, "test");
		img.ptr = mlx_new_image(mlx, SIZE_X, SIZE_Y);
		img.meml = mlx_get_data_addr(img.ptr, &b_per_p, &(img.sizel), &endian);

		pt1.x = 300;
		pt1.y = 300;
		pt2.x = 500;
		pt2.y = 300;
		draw_line(pt1, pt2, img);
		pt2.x = 500;
		pt2.y = 200;
		draw_line(pt1, pt2, img);
		pt2.x = 400;
		pt2.y = 500;
		draw_line(pt1, pt2, img);
		pt2.x = 400;
		pt2.y = 100;
		draw_line(pt1, pt2, img);
		pt2.x = 200;
		pt2.y = 500;
		draw_line(pt1, pt2, img);
		pt2.x = 200;
		pt2.y = 100;
		draw_line(pt1, pt2, img);
		pt2.x = 100;
		pt2.y = 400;
		draw_line(pt1, pt2, img);
		pt2.x = 100;
		pt2.y = 200;
		draw_line(pt1, pt2, img);
		pt2.x = 300;
		pt2.y = 500;
		draw_line(pt1, pt2, img);
		pt2.x = 300;
		pt2.y = 100;
		draw_line(pt1, pt2, img);
		pt2.x = 100;
		pt2.y = 300;
		draw_line(pt1, pt2, img);
		pt2.x = 500;
		pt2.y = 400;
		draw_line(pt1, pt2, img);
		mlx_put_image_to_window(mlx, win, img.ptr, 1, 1);
		mlx_key_hook(win, my_key_func, 0);
		mlx_loop(mlx);
	}
	return (1);
}
