/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:28:45 by vroussea          #+#    #+#             */
/*   Updated: 2016/03/21 11:41:32 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
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
	void	*img;
	int		**map;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*memloc;
	int		x;
	int		y;
	int		i;
	int		j;

	map = NULL;
	if (argc == 2)
	{
		file_reader(argv[1], &map);
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
		win = mlx_new_window(mlx, x, y, "test");
		img = mlx_new_image(mlx, x, y);
		memloc = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);

		draw_line(200, 200, 400, 300, size_line, memloc);
		draw_line(200, 200, 400, 100, size_line, memloc);
		draw_line(200, 200, 300, 400, size_line, memloc);
		draw_line(200, 200, 300, 1, size_line, memloc);
		draw_line(200, 200, 100, 400, size_line, memloc);
		draw_line(200, 200, 100, 1, size_line, memloc);
		draw_line(200, 200, 1, 300, size_line, memloc);
		draw_line(200, 200, 1, 100, size_line, memloc);
		mlx_put_image_to_window(mlx, win, img, 1, 1);
		mlx_key_hook(win, my_key_func, 0);
		mlx_loop(mlx);
	}
	return (1);
}
