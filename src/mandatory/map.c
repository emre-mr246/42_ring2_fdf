/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:34:45 by emgul             #+#    #+#             */
/*   Updated: 2024/06/22 05:59:08 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/message.h"
#include "../../inc/fdf.h"
#include "../../lib/libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

int	get_height(char *map_name, t_fdf *fdf)
{
	char	*line;
	int		fd;
	int		height;

	height = 0;
	fd = open(map_name, O_RDONLY);
	if (!fd)
		exit_with_error(ERR_OPEN, fdf);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		height++;
	}
	if (line)
		free(line);
	close(fd);
	return (height);
}

static int	get_width(char *map_name, t_fdf *fdf)
{
	char	*line;
	char	**split_line;
	int		fd;
	int		width;

	fd = open(map_name, O_RDONLY);
	if (!fd)
		exit_with_error(ERR_OPEN, fdf);
	line = get_next_line(fd);
	if (!line)
		exit_with_error(ERR_LINE, fdf);
	split_line = ft_split(line, ' ');
	free(line);
	width = 0;
	while (split_line[width] && ft_strncmp(split_line[width], "\n",
			ft_strlen(split_line[width])))
		width++;
	free_split(split_line);
	if (!valid_width(fd, width))
		return (0);
	close(fd);
	return (width);
}

static void	center_to_origin(t_map *map)
{
	t_point	*point;
	int		width;
	int		height;
	int		x;
	int		y;

	width = map->width;
	height = map->height;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			point = &map->matrix[y][x];
			point->x -= width / 2;
			point->y -= height / 2;
			x++;
		}
		y++;
	}
}

void	create_map(t_fdf *fdf)
{
	fdf->map->height = get_height(fdf->map_name, fdf);
	fdf->map->width = get_width(fdf->map_name, fdf);
	if ((!fdf->map->width) || (fdf->map->width < 2) || (fdf->map->height < 2))
		exit_with_error(ERR_MAP_DIMENSION, fdf);
	init_matrix(fdf, fdf->map);
	get_matrix(fdf);
	center_to_origin(fdf->map);
	fdf->map->min_z_clr = fdf->map->min_z;
}
