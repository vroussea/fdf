/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:19:20 by vroussea          #+#    #+#             */
/*   Updated: 2016/04/04 21:26:54 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"

# define SIZE_X 1800
# define SIZE_Y 1400
# define CST 0.75

typedef struct	s_img
{
	int		sizel;
	char	*meml;
	void	*ptr;
}				t_img;

typedef struct	s_pt
{
	int		x;
	int		y;
	char	col[8];
}				t_pt;

int				file_reader(char *file, int	***map);
void			draw_line(t_pt pt1, t_pt pt2, t_img file);
void			para_caller(int **map, t_img img);

#endif
