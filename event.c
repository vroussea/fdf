/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 21:29:56 by vroussea          #+#    #+#             */
/*   Updated: 2016/04/25 19:04:00 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h> /////////////////

int	key_hook(int keycode, t_env *env)
{
	if (keycode == 36 || keycode == 76)
		if (!(put_image(env->map, *env)))
			exit(0);
	if (keycode == 69 || keycode == 78)
	{
		env->px += (keycode == 69 ? 0.2 : -0.2);
		env->mtx[0][3] += (keycode == 69 ? -20 - (env->px) : 20 + (env->px));
		env->mtx[1][3] += (keycode == 69 ? -20 - (env->py) : 20 + (env->py));
		env->px = (env->px <= 0.2 ? 0.2 : env->px);
		env->py = env->px;
	}
	if (keycode == 40 || keycode == 37)
	{
		env->tet += (keycode == 40 ? 90 : -90);
		env->mtx[1][1] = cos(env->tet);
		env->mtx[0][1] = -sin(env->tet);
		env->mtx[1][0] = sin(env->tet);
		env->mtx[0][0] = cos(env->tet);
		printf("cos(%d) = %f\n", env->tet, cos(env->tet));
		printf("sin(%d) = %f\n", env->tet, sin(env->tet));
		printf("-sin(%d) = %f\n", env->tet, -sin(env->tet));
	}
	if (keycode == 91)
		env->oy -= 0.1;
	if (keycode == 84)
		env->oy += 0.1;
	if (keycode == 86)
		env->ox += 0.1;
	if (keycode == 88)
		env->ox -= 0.1;
	if (keycode == 124)
		env->mtx[0][3] += 20 + (env->px);
		//env->dx += 20 + (env->px / 2);
	if (keycode == 123)
		env->mtx[0][3] -= 20 - (env->px);
		//env->dx -= 20 - (env->px / 2);
	if (keycode == 126)
		env->mtx[1][3] -= 20 - (env->py);
		//env->dy -= 20 - (env->py / 2);
	if (keycode == 125)
		env->mtx[1][3] += 20 + (env->py);
		//env->dy += 20 + (env->py / 2);
	if (keycode == 53)
	{
		ft_putendl("Programme fermé");
		exit(0);
	}
	if (!(put_image(env->map, *env)))
		exit(0);
	return (1);
}
