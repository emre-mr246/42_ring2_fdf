/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 02:59:44 by emgul             #+#    #+#             */
/*   Updated: 2024/06/22 05:58:43 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/message.h"
#include "../../inc/fdf.h"
#include "../../lib/libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

static void	fill_matrix(t_fdf *fdf, char **split_line, int height)
{
	t_point	*point;
	char	*color_str;
	int		i;

	i = 0;
	while (i < fdf->map->width)
	{
		point = &fdf->map->matrix[height][i];
		point->x = (float)i;
		point->y = (float)height;
		point->z = (float)ft_atoi(split_line[i]);
		if (point->z > fdf->map->max_z)
			fdf->map->max_z = point->z;
		if (point->z < fdf->map->min_z)
			fdf->map->min_z = point->z;
		color_str = ft_strchr(split_line[i], ',');
		if (color_str)
			point->color = ft_atoi_base(color_str + 3, HEX_BASE);
		else
			point->color = HEX_WHITE;
		i++;
	}
}

void	get_matrix(t_fdf *fdf)
{
	int		fd;
	char	*line;
	char	**split_line;
	int		height;

	fd = open(fdf->map_name, O_RDONLY);
	if (!fd)
		exit_with_error(ERR_OPEN, fdf);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		split_line = ft_split(line, ' ');
		free(line);
		fill_matrix(fdf, split_line, height);
		free_split(split_line);
		height++;
	}
	close(fd);
}
