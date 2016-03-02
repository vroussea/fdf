/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:28:45 by vroussea          #+#    #+#             */
/*   Updated: 2016/03/02 18:28:19 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

int	my_key_func(int keycode, void *param)
{
	int	tmp;

	tmp = (int)param;
	ft_putendl(ft_itoa(keycode));
	if (keycode == 53)
	{
		ft_putendl("mdr");
		return (0);
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

	map = NULL;
	if (argc == 2)
		file_reader(argv[1], &map);
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
