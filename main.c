/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:28:45 by vroussea          #+#    #+#             */
/*   Updated: 2016/05/02 22:15:00 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"
#include <stdio.h>

/*static int		nb_ptx(int **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = j + map[i][0];
		i++;
	}
	return (j);
}

static int		nb_pty(int **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = j + map[i][0];
		i++;
	}
	return (j);
}*/

static void		loop(t_env env)
{
		mlx_hook(env.win, 2, 0, key_funct, &env);
		mlx_hook(env.win, 17, 0, quit_funct, NULL);
		mlx_loop(env.mlx);
}

int				main(int argc, char **argv)
{
	t_env	env;
	//int		nb_x;
	//int		nb_y;

	if (argc == 2)
	{
		env.sx = 2560;              ////////////////// erase when menu is on
		env.sy = 1310; /////////////////
		if (!(env.mtx = ft_matrixid(3)))
			return (0);
		ft_putendl("matid");
		env.tx = 200;
		env.ty = 200;
		env.x = 0;
		env.y = 0;
		env.z = 0;
		env.px = 2;
		env.py = 2;
		if (!(env.mlx = mlx_init()))
			return (0);
		ft_putendl("mlx init");
		if (!(env.win = mlx_new_window(env.mlx, env.sx, env.sy, "FdF")))
			return (0);
		env.map = NULL;
		ft_putendl("win init");
		if (!file_reader(argv[1], &(env.map)))
		{
			ft_putendl("Error with map file or malloc !");
			return (0);
		}
		ft_putendl("map lu");
		loop(env);
	}
	return (1);
}
