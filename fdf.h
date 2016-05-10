/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:19:20 by vroussea          #+#    #+#             */
/*   Updated: 2016/05/08 18:25:36 by vroussea         ###   ########.fr       */
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
	void	*mlx;
	void	*win;
	int		sx;
	int		sy;
	void	*img;
	char	*meml;
	int		**map;
	double	**mtx;
	int		sizel;
	int		x;
	int		y;
	int		z;
	double	zm;
	double	alt;
	int		tx;
	int		ty;
	int		color[5];
}				t_env;

typedef struct	s_pt
{
	int		x;
	int		y;
	int		z;
	int		col;
}				t_pt;

int				file_reader(char *file, int	***map);
void			line(t_pt pt1, t_pt pt2, t_env env);
int				key_funct(int keycode, t_env *env);
int				quit_funct();
int				put_image(int **map, t_env env);
void			rotate(int keycode, t_env *env);
int				nb_pty(int **map);

#endif
