/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:19:20 by vroussea          #+#    #+#             */
/*   Updated: 2016/04/13 18:39:21 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"

# define CST 0.75

/*
** px/py space between 2 points
** sx/sy screen size
*/

typedef struct	s_env
{
	int		sx;
	int		sy;
	void	*mlx;
	void	*win;
	int		**map;
	int		sizel;
	double	mtx[4][4];
	double	ox;
	double	oy;
	double	px;
	double	py;
	double	dx;
	double	dy;
	char	*meml;
	void	*img;
}				t_env;

typedef struct	s_pt
{
	int		x;
	int		y;
	int		col;
}				t_pt;

int				file_reader(char *file, int	***map);
void			line(t_pt pt1, t_pt pt2, t_env env);
int				key_hook(int keycode, t_env *env);
int				put_image(int **map, t_env env);

#endif
