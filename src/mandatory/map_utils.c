/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 02:58:44 by emgul             #+#    #+#             */
/*   Updated: 2024/06/21 05:38:56 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include "../../lib/libft/libft.h"
#include <math.h>

int	valid_width(int file_descriptor, int width)
{
	char	*line;
	char	**split_line;
	int		temp_width;

	while (1)
	{
		line = get_next_line(file_descriptor);
		if (!line || !ft_isprint(*line))
			break ;
		split_line = ft_split(line, ' ');
		temp_width = 0;
		while (split_line[temp_width])
			temp_width++;
		free_split(split_line);
		if (!(temp_width == width || temp_width == width - 1
				|| temp_width == width + 1))
			return (0);
		free(line);
	}
	if (line)
		free(line);
	return (1);
}

void	scale_map(t_fdf *fdf, t_point *start_point, t_point *end_point)
{
	float	scale;
	float	value;

	scale = fdf->cam->scale;
	if (fdf->map->max_z > fdf->map->min_z)
		value = fabs(fdf->map->max_z - fdf->map->min_z);
	else
		value = fabs(fdf->map->min_z - fdf->map->max_z);
	start_point->x *= scale;
	start_point->y *= scale;
	start_point->z *= scale * (value * 0.01);
	end_point->x *= scale;
	end_point->y *= scale;
	end_point->z *= scale * (value * 0.01);
}
