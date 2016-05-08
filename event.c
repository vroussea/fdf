/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 21:29:56 by vroussea          #+#    #+#             */
/*   Updated: 2016/05/08 16:40:52 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static void	zoom(int keycode, t_env *env)
{
	if (keycode == 69 || keycode == 78)
	{
		env->zm += (keycode == 69 ? 0.2 : -0.2);
		env->tx += (keycode == 69 ? -20 - (env->zm) : 20 + (env->zm));
		env->ty += (keycode == 69 ? -20 - (env->zm) : 20 + (env->zm));
		env->zm = (env->zm <= 0.2 ? 0.2 : env->zm);
	}
}

static void	translate(int keycode, t_env *env)
{
	if (keycode == 124)
		env->tx += 12 + (env->zm);
	if (keycode == 123)
		env->tx -= 12 - (env->zm);
	if (keycode == 126)
		env->ty -= 12 - (env->zm);
	if (keycode == 125)
		env->ty += 12 + (env->zm);
}

static void	altitude(int keycode, t_env *env)
{
	if (keycode == 116 || keycode == 121)
	{
		env->alt += (keycode == 116 ? 0.1 : -0.1);
		printf("altitude : %2F\n", env->alt);
	}
}

int			key_funct(int keycode, t_env *env)
{
	if (keycode == 36 || keycode == 76)
		if (!(put_image(env->map, *env)))
			exit(0);
	zoom(keycode, env);
	translate(keycode, env);
	rotate(keycode, env);
	altitude(keycode, env);
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
