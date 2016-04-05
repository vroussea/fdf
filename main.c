/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:28:45 by vroussea          #+#    #+#             */
/*   Updated: 2016/04/05 19:04:36 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"

static int		my_key_func(int keycode, void *param)
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
	int		bpp;
	int		edan;
	t_img	*img;

	if (!(img = (t_img *)ft_memalloc(sizeof(t_img))))
		return (NULL);
	if (!(img->ptr = mlx_new_image(env->mlx, env->szx, env->szy)))
		return (NULL);
	if (!(img->meml = mlx_get_data_addr(img->ptr, &bpp, &(img->sizel), &edan)))
		return (NULL);
	img->env = env;
	return (img);
}

static t_env	*env-Init()
{
	t_env	*env;

	if (!(env->mlx = mlx_init()))
		return (0);
	env->szx = 2560;
	env->szy = 1310;
	if (!(env->win = mlx_new_window(env->mlx, env->szx, env->szy, "test")))
		return (0);
	return (env);
}

int				main(int argc, char **argv)
{
	t_env	*env;
	int		**map;
	t_img	*img;

	map = NULL;
	if (argc == 2)
	{
		if (!file_reader(argv[1], &map))
		{
			ft_putendl("Error with map file or malloc !");
			return (0);
		}
		if (!(img = img_init(env)))
			return (0);
		para_caller(map, img);
		mlx_put_image_to_window(env->mlx, env->win, img->ptr, 1, 1);
		mlx_key_hook(env->win, my_key_func, 0);
		mlx_loop(env->mlx);
	}
	return (1);
}
