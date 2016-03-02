/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:21:57 by vroussea          #+#    #+#             */
/*   Updated: 2016/03/02 18:56:04 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"

static int	init_map(int ***map, char *file)
{
	int		i;
	int		ret;
	int		fd;
	char	*line;
	int		size;

	fd = open(file, O_RDONLY);
	if ((ret = get_next_line(fd, &line)) == -1)
		return (0);
	size = ft_strlen(line);
	if (!(*map = (int **)ft_memalloc(sizeof(int *) * size)))
		return (0);
	i = 0;
	while (i < size)
	{
		if (!(*map[i] = (int *)ft_memalloc(sizeof(int) * size)))
			return (0);
		i++;
	}
	close(fd);
	return (size);
}

int			file_reader(char *file, int ***map)
{
	int		fd;
	int		ret;
	char	*line;
	int		size;

	if ((size = init_map(map, file)) == 0)
		return (0);
	fd = open(file, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putendl(line);
	}
	close(fd);
	return ((ret < 0) ? 0 : 1);
}
