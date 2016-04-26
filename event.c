/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 21:29:56 by vroussea          #+#    #+#             */
/*   Updated: 2016/04/26 21:45:45 by vroussea         ###   ########.fr       */
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
	if (!(put_image(env->map, *env)))
		quit_funct();
}

void	translate(int keycode, t_env *env)
{
	if (keycode == 124)
		env->mtx[0][3] += 12 + (env->px);
	if (keycode == 123)
		env->mtx[0][3] -= 12 - (env->px);
	if (keycode == 126)
		env->mtx[1][3] -= 12 - (env->py);
	if (keycode == 125)
		env->mtx[1][3] += 12 + (env->py);
	if (!(put_image(env->map, *env)))
		quit_funct();
}

void	rotate(int keycode, t_env *env)
{
	if (keycode == 82 || keycode == 65)
		env->tet += (keycode == 82 ? 1 : -1);
	if (keycode == 86 || keycode == 88)
		env->alf += (keycode == 86 ? 1 : -1);
	if (keycode == 84 || keycode == 91)
		env->bet += (keycode == 84 ? 1 : -1);
	ft_putendl("mdr");
	/*env->mtx[2][2] = cos(env->tet * 0.0174533);
	env->mtx[1][2] = sin(env->tet * 0.0174533);
	env->mtx[2][1] = -sin(env->tet * 0.0174533);
	env->mtx[1][1] = cos(env->tet * 0.0174533);
	env->mtx[1][1] += cos(env->alf * 0.0174533);
	env->mtx[1][2] += -sin(env->alf * 0.0174533);
	env->mtx[2][1] += sin(env->alf * 0.0174533);
	env->mtx[2][2] += cos(env->alf * 0.0174533);
	env->mtx[0][0] = cos(env->bet * 0.0174533);
	env->mtx[0][2] = sin(env->bet * 0.0174533);
	env->mtx[2][0] = -sin(env->bet * 0.0174533);
	env->mtx[2][2] += cos(env->bet * 0.0174533);*/
	ft_putendl("mdr");
	if (!(put_image(env->map, *env)))
		quit_funct();
}

int		key_funct(int keycode, t_env *env)
{
	if (keycode == 36 || keycode == 76)
		if (!(put_image(env->map, *env)))
			exit(0);
	zoom(keycode, env);
	translate(keycode, env);
	rotate(keycode, env);
	if (keycode == 53 || keycode == 17)
		quit_funct();
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
