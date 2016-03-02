/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:21:57 by vroussea          #+#    #+#             */
/*   Updated: 2016/03/02 22:54:37 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"

static int	sizer_x(char *file)
{
	int	size_x;
	char *line;
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
	char 	*line;
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
	int		i;
	int		size_x;
	int		size_y;

	size_x = sizer_x(file);
	size_y = sizer_y(file);
	ft_putstr("size_x : ");
	ft_putendl(ft_itoa(size_x));
	ft_putstr("size_y : ");
	ft_putendl(ft_itoa(size_y));
	if (!(*map = (int **)ft_memalloc(sizeof(int *) * size_y)))
		return (0);
	i = 0;
	while (i < size_y)
	{
		if (!((*map)[i] = (int *)ft_memalloc(sizeof(int) * size_x)))
			return (0);
		i++;
	}
	return (1);
}

int			file_reader(char *file, int ***map)
{
	int		fd;
	int		ret;
	char	*line;

	if (!(size = init_map(map, file)))
		return (0);
	ft_putendl("mdr2");
	if (!test_file(file))
		return (0);
	fd = open(file, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putendl(line);
	}
	close(fd);
	return ((ret < 0) ? 0 : 1);
}
