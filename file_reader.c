/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:21:57 by vroussea          #+#    #+#             */
/*   Updated: 2016/03/18 15:23:19 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"

static int	test_file(char *file)
{
	int		fd;
	int		ret;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		 i = 0;
		if (ret < 0 || line[i] == '\0')
			return (0);
		while (line[i] != '\0')
		{
			if (!ft_isdigit(line[i]) && line[i] != ' ')
				return (0);
			i++;
		}
		ft_strdel(&line);
	}
	close(fd);
	return (1);
}

static int	init_map(int ***map, char *file)
{
	int		size_y;
	char	*line;
	int		fd;
	int		ret;

	fd = open(file, O_RDONLY);
	size_y = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_strdel(&line);
		size_y++;
	}
	if (ret == -1)
		return (0);
	close(fd);
	if (!(*map = (int **)ft_memalloc(sizeof(int *) * (size_y + 1))))
		return (0);
	(*map)[size_y] = NULL;
	return (1);
}

static int	*line_filler(char *line, int *mapline)
{
	char	**tab;
	int		i;
	int		nb_int;

	tab = ft_strsplit(line, ' ');
	nb_int = 0;
	while (tab[nb_int] != NULL)
		nb_int++;
	if (!(mapline = (int *)ft_memalloc(sizeof(int) * (nb_int + 1))))
		return (NULL);
	mapline[0] = nb_int;
	i = 0;
	while (tab[i])
	{
		mapline[i + 1] = ft_atoi(tab[i]);
		i++;
	}
	return (mapline);
}

int			file_reader(char *file, int ***map)
{
	int		fd;
	int		ret;
	char	*line;
	int		i;

	if (!(init_map(map, file)))
		return (0);
	if (!test_file(file))
		return (0);
	i = 0;
	fd = open(file, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!((*map)[i] = line_filler(line, (*map)[i])))
			return (0);
		ft_strdel(&line);
		i++;
	}
	close(fd);
	return ((ret < 0) ? 0 : 1);
}
