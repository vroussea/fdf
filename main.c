/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:28:45 by vroussea          #+#    #+#             */
/*   Updated: 2016/04/11 19:10:18 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
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

	if (argc == 2)
	{
		env.px = 1;
		env.py = 1;
		env.sx = 2560;              ////////////////// erase when menu is on
		env.sy = 1310;                   /////////////////
		env.dx = 100;
		env.dy = 100;
		env.ox = 1;
		env.oy = 1;
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
