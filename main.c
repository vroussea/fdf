/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:28:45 by vroussea          #+#    #+#             */
/*   Updated: 2016/03/05 20:13:22 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

int	my_key_func(int keycode, void *param)
{
	int	tmp;

	tmp = (int)param;
	ft_putendl(ft_itoa(keycode));
	if (keycode == 53)
	{
		ft_putendl("mdr");
		exit(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		**map;
	int		x;
	int		y;
	int		a;
	int		i;
	int		j;

	map = NULL;
	if (argc == 2)
		file_reader(argv[1], &map);
	ft_putnbr(map[0][0]);
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (j < map[i][0])
		{
			ft_putnbr(map[i][j]);
			j++;
			if (map[i][j] < 10)
				ft_putchar(' ');
			ft_putchar(' ');
		}
		ft_putchar('\n');
		i++;
	}
	x = 50;
	y = 50;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "test");
	while (x <= 450 && y <= 450)
	{
		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		x++;
		y++;
	}
	x = 50;
	y = 450;
	while (x <= 450 && y >= 50)
	{
		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		x++;
		y--;
	}
	if ((a = mlx_key_hook(win, my_key_func, 0)) == 0)
		return (0);
	ft_putstr("a : ");
	ft_putendl(ft_itoa(a));
	mlx_loop(mlx);
	return (1);
}
