/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:28:45 by vroussea          #+#    #+#             */
/*   Updated: 2016/04/05 22:16:24 by vroussea         ###   ########.fr       */
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

static t_img	*img_init(t_env *env)
{
	t_img	*img;

	if (!(img = (t_img *)ft_memalloc(sizeof(t_img))))
		return (NULL);
	img->sbpx = 2;
	img->sbpy = 1;
	img->env = env;
	return (img);
}

static t_env	*env_init()
{
	t_env	*env;

	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		return (0);
	if (!(env->mlx = mlx_init()))
		return (0);
	env->szx = 2560;              ////////////////// erase when menu is on
	env->szy = 1310;                   /////////////////
	if (!(env->win = mlx_new_window(env->mlx, env->szx, env->szy, "test")))
		return (0);
	return (env);
}

int				main(int argc, char **argv)
{
	t_env	*env;
	t_img	*img;

	if (argc == 2)
	{
		if (!(env = env_init()))
			return (0);
		env->map = NULL;
		if (!file_reader(argv[1], &(env->map)))
		{
			ft_putendl("Error with map file or malloc !");
			return (0);
		}
		if (!(img = img_init(env)))
			return (0);
		mlx_key_hook(env->win, key_hook, img);
		mlx_loop(env->mlx);
	}
	return (1);
}
