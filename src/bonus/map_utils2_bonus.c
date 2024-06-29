/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:12:13 by emgul             #+#    #+#             */
/*   Updated: 2024/06/29 23:14:04 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf_bonus.h"
#include "../../lib/libft/libft.h"
#include <math.h>

static int	calculate_color_for_point(double relative_z, double z_scale_factor)
{
	double	scaled_color;

	if (z_scale_factor >= 0)
		scaled_color = pow(relative_z, 1.5) * 255.0 * z_scale_factor;
	else
		scaled_color = pow(1.0 - relative_z, 1.5) * 255.0 * -z_scale_factor;
	if (scaled_color > 255.0)
		scaled_color = 255.0;
	else if (scaled_color < 0.0)
		scaled_color = 0.0;
	return ((int)scaled_color);
}

static void	handle_color_for_point(t_fdf *fdf, t_point *point)
{
	double	clr;
	double	relative_z;
	int		final_color;

	clr = (double)(fdf->map->max_z - fdf->map->min_z);
	relative_z = ((double)point->z - fdf->map->min_z) / clr;
	final_color = calculate_color_for_point(relative_z,
			fdf->cam->z_scale_factor);
	point->color = create_rgb(0, final_color, 0);
}

void	handle_color_for_height_dynamic(t_fdf *fdf)
{
	t_point	**point_matrix;
	int		x;
	int		y;

	point_matrix = fdf->map->matrix;
	x = 0;
	while (x < fdf->map->height)
	{
		y = 0;
		while (y < fdf->map->width)
		{
			handle_color_for_point(fdf, &point_matrix[x][y]);
			y++;
		}
		x++;
	}
}
