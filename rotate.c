/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 19:15:57 by vroussea          #+#    #+#             */
/*   Updated: 2016/05/08 16:42:16 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	matrixmul(double **mat1, double **mat2, int size)
{
	double	mat[size][size];
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i++ < size)
	{
		j = 0;
		while (j++ < size)
		{
			k = 0;
			mat[i - 1][j - 1] = 0;
			while (k++ < size)
				mat[i - 1][j - 1] += mat1[i - 1][k - 1] * mat2[k - 1][j - 1];
		}
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j++ < size)
			mat1[i][j - 1] = mat[i][j - 1];
		i++;
	}
}

static void	rotate_x(int keycode, t_env *env)
{
	double **mat;

	if (keycode == 87 || keycode == 91)
		env->x += (keycode == 87 ? 1 : -1);
	mat = ft_matrixid(3);
	mat[1][1] = cos(env->x * 0.0174533);
	mat[1][2] = sin(env->x * 0.0174533);
	mat[2][1] = -sin(env->x * 0.0174533);
	mat[2][2] = cos(env->x * 0.0174533);
	matrixmul(env->mtx, mat, 3);
	ft_tabdel((void ***)&mat);
}

static void	rotate_y(int keycode, t_env *env)
{
	double **mat;

	if (keycode == 86 || keycode == 88)
		env->y += (keycode == 88 ? 1 : -1);
	mat = ft_matrixid(3);
	mat[0][0] = cos(env->y * 0.0174533);
	mat[0][2] = sin(env->y * 0.0174533);
	mat[2][0] = -sin(env->y * 0.0174533);
	mat[2][2] = cos(env->y * 0.0174533);
	matrixmul(env->mtx, mat, 3);
	ft_tabdel((void ***)&mat);
}

static void	rotate_z(int keycode, t_env *env)
{
	double **mat;

	if (keycode == 89 || keycode == 92)
		env->z += (keycode == 89 ? 1 : -1);
	mat = ft_matrixid(3);
	mat[0][0] = cos(env->z * 0.0174533);
	mat[0][1] = -sin(env->z * 0.0174533);
	mat[1][0] = sin(env->z * 0.0174533);
	mat[1][1] = cos(env->z * 0.0174533);
	matrixmul(env->mtx, mat, 3);
	ft_tabdel((void ***)&mat);
}

void		rotate(int keycode, t_env *env)
{
	rotate_x(keycode, env);
	rotate_y(keycode, env);
	rotate_z(keycode, env);
}
