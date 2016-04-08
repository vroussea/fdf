/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:19:20 by vroussea          #+#    #+#             */
/*   Updated: 2016/04/08 18:28:56 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"

# define CST 0.75

typedef struct	s_env
{
	int		szx;
	int		szy;
	void	*mlx;
	void	*win;
	int		**map;
}				t_env;

typedef struct	s_img
{
	int			sizel;
	double		sbpx;
	double		sbpy;
	char		*meml;
	void		*ptr;
	t_env		*env;
}				t_img;

typedef struct	s_pt
{
	int		x;
	int		y;
	int		col;
}				t_pt;

int				file_reader(char *file, int	***map);
void			line(t_pt pt1, t_pt pt2, t_img *img);
int				key_hook(int keycode, t_img *img);
int				put_image(int **map, t_img *img);

#endif
