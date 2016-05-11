/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 21:29:56 by vroussea          #+#    #+#             */
/*   Updated: 2016/05/11 20:37:20 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static void	zoom(int keycode, t_env *env)
{
	int	nb_x;
	int	nb_y;

	if (keycode == 69 || keycode == 78)
	{
		nb_x = env->map[0][0];
		nb_y = nb_pty(env->map);
		env->zm += (keycode == 69 ? 0.4 : -0.4);
		if (keycode == 69 && env->zm >= 0)
		{
			env->tx -= (nb_x * (env->zm + 0.4) - nb_x * env->zm) / 2;
			env->ty -= (nb_y * (env->zm + 0.4) - nb_y * env->zm) / 2;
		}
		if (keycode == 78 && env->zm >= 0)
		{
			env->tx += (nb_x * (env->zm + 0.4) - nb_x * env->zm) / 2;
			env->ty += (nb_y * (env->zm + 0.4) - nb_y * env->zm) / 2;
		}
		env->zm = (env->zm <= 0.2 ? 0.2 : env->zm);
	}
}

static void	translate(int keycode, t_env *env)
{
	if (keycode == 124)
		env->tx += 25;
	if (keycode == 123)
		env->tx -= 25;
	if (keycode == 126)
		env->ty -= 25;
	if (keycode == 125)
		env->ty += 25;
}

int			key_funct(int keycode, t_env *env)
{
	if (keycode == 36 || keycode == 76)
		if (!(put_image(env->map, *env)))
			exit(0);
	if (keycode == 12)
	{
		ft_putstr("x : ");
		ft_putendl(ft_itoa(env->x));
		ft_putstr("y : ");
		ft_putendl(ft_itoa(env->y));
		ft_putstr("z : ");
		ft_putendl(ft_itoa(env->z));
	}
	zoom(keycode, env);
	translate(keycode, env);
	rotate(keycode, env);
	if (keycode == 116 || keycode == 121)
		env->alt += (keycode == 116 ? 0.02 : -0.02);
	if (keycode == 53 || keycode == 17)
		quit_funct();
	if (!(put_image(env->map, *env)))
		quit_funct();
	return (1);
}

int			quit_funct(void)
{
	ft_putendl("Programme fermé");
	exit(0);
	return (1);
}
