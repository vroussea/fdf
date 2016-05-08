/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:28:45 by vroussea          #+#    #+#             */
/*   Updated: 2016/05/08 16:54:52 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"
#include <stdio.h>

static int		nb_pty(int **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		i++;
	}
	return (i);
}

static void		loop(t_env env)
{
		mlx_hook(env.win, 2, 0, key_funct, &env);
		mlx_hook(env.win, 17, 0, quit_funct, NULL);
		mlx_loop(env.mlx);
}

int				main(int argc, char **argv)
{
	t_env	env;
	int		nb_x;
	int		nb_y;

	if (argc == 2)
	{
		env.map = NULL;
		if (!file_reader(argv[1], &(env.map)))
		{
			ft_putendl("Error with map file or malloc !");
			return (0);
		}
		env.sx = 2560;              ////////////////// erase when menu is on
		env.sy = 1310; /////////////////
		nb_x = env.map[0][0];
		nb_y = nb_pty(env.map);
		ft_putstr("nb_x : ");
		ft_putendl(ft_itoa(nb_x));
		ft_putstr("nb_y : ");
		ft_putendl(ft_itoa(nb_y));
		env.zm = (nb_x > 2 * nb_y  ? (env.sx - 400) / nb_x : (env.sy - 400) / nb_y);
		if (!(env.mtx = ft_matrixid(3)))
			return (0);
		env.tx = 200;
		env.ty = 200;
		env.x = 0;
		env.y = 0;
		env.z = 0;
		env.alt = 0.5;
		if (!(env.mlx = mlx_init()))
			return (0);
		if (!(env.win = mlx_new_window(env.mlx, env.sx, env.sy, "FdF")))
			return (0);
		if (!(env.img = mlx_new_image(env.mlx, env.sx, env.sy)))
			return (0);
		loop(env);
	}
	return (1);
}
