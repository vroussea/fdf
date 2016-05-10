/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:28:45 by vroussea          #+#    #+#             */
/*   Updated: 2016/05/08 22:33:18 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

static void	color_scaling(t_env *env)
{
	int	i;
	int	j;
	int	max;
	
	i = 0;
	max = 0;
	while (env->map[i] != NULL)
	{
		j = 1;
		while (j <= env->map[0][0])
		{
			max = (env->map[i][j] > max ? env->map[i][j] : max);
			j++;
		}
		i++:
	}
	env->color[0] = max * 3 * 100;
	env->color[1] = max * 65 * 100;
	env->color[2] = max * 80 * 100;
	env->color[3] = max * 95 * 100;
	env->color[4] = max * 100 * 100;
}

int		nb_pty(int **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
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
		env.zm = (nb_x > 1.5 * nb_y)  ? env.sx / nb_x : env.sy / nb_y;
		env.zm = (env.zm < 0.2 ? 0.2: env.zm);
		if (!(env.mtx = ft_matrixid(3)))
			return (0);
		env.tx = (env.sx - nb_x * env.zm) * 0.75;
		env.ty = (env.sy - nb_y * env.zm) * 1.5;
		env.x = -49;
		env.y = 3;
		env.z = 14;
		//env.x = 0;
		//env.y = 0;
		//env.z = 0;
		env.alt = 0.02;
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
