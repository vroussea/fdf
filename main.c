/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:28:45 by vroussea          #+#    #+#             */
/*   Updated: 2016/05/11 22:05:35 by vroussea         ###   ########.fr       */
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
		while (j++ <= env->map[0][0])
			max = (env->map[i][j - 1] > max ? env->map[i][j - 1] : max);
		i++;
	}
	env->color[0][0] = max * 0 / 100;
	env->color[1][0] = max * 0.5 / 100;
	env->color[2][0] = max * 8 / 100;
	env->color[3][0] = max * 45 / 100;
	env->color[4][0] = max * 65 / 100;
	env->color[0][1] = 0x00FFFF66;
	env->color[1][1] = 0x00006600;
	env->color[2][1] = 0x00003300;
	env->color[3][1] = 0x00331900;
	env->color[4][1] = 0x00FFFFFF;
}

int			nb_pty(int **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

static void	loop(t_env env)
{
	int		nb_x;
	int		nb_y;

	nb_x = env.map[0][0];
	nb_y = nb_pty(env.map);
	env.zm = (nb_x > 1.5 * nb_y ? env.sx / nb_x : env.sy / nb_y);
	env.zm = (env.zm < 0.2 ? 0.2 : env.zm);
	env.tx = (env.sx - nb_x * env.zm) / 2;
	env.ty = (env.sy - nb_y * env.zm) / 2;
	env.x = 0;
	env.y = 0;
	env.z = 0;
	env.alt = 0.04;
	color_scaling(&env);
	mlx_hook(env.win, 2, 0, key_funct, &env);
	mlx_hook(env.win, 17, 0, quit_funct, NULL);
	mlx_loop(env.mlx);
}

int			main(int argc, char **argv)
{
	t_env	env;

	if (argc == 2)
	{
		if (!file_reader(argv[1], &(env.map)))
		{
			ft_putendl("Error with map file or map memory alloc !");
			return (0);
		}
		env.sx = 2560;
		env.sy = 1310;
		if (!(env.mtx = ft_matrixid(3)) ||
			!(env.mlx = mlx_init()) ||
			!(env.win = mlx_new_window(env.mlx, env.sx, env.sy, "FdF")) ||
			!(env.img = mlx_new_image(env.mlx, env.sx, env.sy)))
			return (0);
		loop(env);
	}
	return (1);
}
