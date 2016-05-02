/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 21:29:56 by vroussea          #+#    #+#             */
/*   Updated: 2016/05/02 21:59:33 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdlib.h>

void	zoom(int keycode, t_env *env)
{
	if (keycode == 69 || keycode == 78)
	{
		env->px += (keycode == 69 ? 0.2 : -0.2);
		env->mtx[0][3] += (keycode == 69 ? -20 - (env->px) : 20 + (env->px));
		env->mtx[1][3] += (keycode == 69 ? -20 - (env->py) : 20 + (env->py));
		env->px = (env->px <= 0.2 ? 0.2 : env->px);
		env->py = env->px;
	}
}

void	translate(int keycode, t_env *env)
{
	if (keycode == 124)
		env->tx += 12 + (env->px);
	if (keycode == 123)
		env->tx -= 12 - (env->px);
	if (keycode == 126)
		env->ty -= 12 - (env->py);
	if (keycode == 125)
		env->ty += 12 + (env->py);
}

int		key_funct(int keycode, t_env *env)
{
	ft_putendl("mdr1");
	if (keycode == 36 || keycode == 76)
		if (!(put_image(env->map, *env)))
			exit(0);
	zoom(keycode, env);
	translate(keycode, env);
	ft_putendl("mdrrot");
	if (keycode == 84 || keycode == 91)
		rotate_x(keycode, *env);
	if (keycode == 86 || keycode == 88)
		rotate_y(keycode, *env);
	if (keycode == 82 || keycode == 65)
		rotate_z(keycode, *env);
	if (keycode == 53 || keycode == 17)
		quit_funct();
	ft_putendl("mdrtor");
	if (!(put_image(env->map, *env)))
		quit_funct();
	return (1);
}

int		quit_funct()
{
	ft_putendl("Programme fermé");
	exit(0);
	return (1);
}
