/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:28:45 by vroussea          #+#    #+#             */
/*   Updated: 2016/04/25 18:56:18 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"

/*
** static int		nb_pts(int **map)
** {
**	int	i;
**	int	j;
**
**	i = 0;
**	j = 0;
**	while (map[i] != NULL)
**	{
**		j = j + map[i][0];
**		i++;
**	}
**	return (j);
** }
*/

int				main(int argc, char **argv)
{
	t_env	env;
	int		a;

	if (argc == 2)
	{
		a = 20;
		env.sx = 2560;              ////////////////// erase when menu is on
		env.sy = 1310; /////////////////
		env.mtx[0][0] = 1;
		env.mtx[0][1] = 0;
		env.mtx[0][2] = 0;
		env.mtx[0][3] = 200;
		env.mtx[1][0] = 0;
		env.mtx[1][1] = 1;
		env.mtx[1][2] = 0;
		env.mtx[1][3] = 200;
		env.mtx[2][0] = 0;
		env.mtx[2][1] = 0;
		env.mtx[2][2] = 1;
		env.mtx[2][3] = 0;
		env.mtx[3][0] = 0;
		env.mtx[3][1] = 0;
		env.mtx[3][2] = 0;
		env.mtx[3][3] = 1;
		env.tet = 0;
		env.px = 2;
		env.py = 2;
		/*env.dx = 100;
		env.dy = 100;
		env.ox = 1;
		env.oy = 1;*/
		if (!(env.mlx = mlx_init()))
			return (0);
		if (!(env.win = mlx_new_window(env.mlx, env.sx, env.sy, "FdF")))
			return (0);
		env.map = NULL;
		if (!file_reader(argv[1], &(env.map)))
		{
			ft_putendl("Error with map file or malloc !");
			return (0);
		}
		mlx_key_hook(env.win, key_hook, &env);
		mlx_loop(env.mlx);
	}
	return (1);
}
