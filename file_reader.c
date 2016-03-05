/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:21:57 by vroussea          #+#    #+#             */
/*   Updated: 2016/03/05 20:10:16 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"

static int	sizer_x(char *file)
{
	int		size_x;
	char	*line;
	int		fd;
	int		ret;

	fd = open(file, O_RDONLY);
	if ((ret = get_next_line(fd, &line)) == -1)
		return (0);
	size_x = ft_strlen(line);
	close(fd);
	return (size_x);
}

static int	sizer_y(char *file)
{
	int		size_y;
	char	*line;
	int		fd;
	int		ret;

	fd = open(file, O_RDONLY);
	size_y = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
		size_y++;
	if (ret == -1)
		return (0);
	close(fd);
	return (size_y);
}

static int	init_map(int ***map, char *file)
{
	int		size_x;
	int		size_y;

	size_x = sizer_x(file);
	size_y = sizer_y(file);
	if (!(*map = (int **)ft_memalloc(sizeof(int *) * (size_y + 1))))
		return (0);
	(*map)[size_y] = NULL;
	return (1);
}

static int	line_filler(char *line, int *mapline)
{
	char	**tab;
	int		i;
	int		nb_int;

	tab = ft_strsplit(line, ' ');
	nb_int = 0;
	while (tab[nb_int] != NULL)
		nb_int++;
	ft_putstr("nb_int + 1 : ");
	ft_putendl(ft_itoa(nb_int + 1));
	if (!(mapline = (int *)ft_memalloc(sizeof(int) * (nb_int + 1))))
		return (0);
	mapline[0] = nb_int;
	i = 0;
	while (tab[i])
	{
		mapline[i + 1] = ft_atoi(tab[i]);
		i++;
	}
	return (1);
}

int			file_reader(char *file, int ***map)
{
	int		fd;
	int		ret;
	char	*line;
	int		i;

	if (!(init_map(map, file)))
		return (0);
	//if (!test_file(file))
	//	return (0);
	i = 0;
	fd = open(file, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(line_filler(line, (*map)[i])))
			return (0);
		i++;
	}
	close(fd);
	return ((ret < 0) ? 0 : 1);
}
