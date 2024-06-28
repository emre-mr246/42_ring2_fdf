/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 01:53:07 by emgul             #+#    #+#             */
/*   Updated: 2024/06/28 23:05:18 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include <math.h>
#include <stdlib.h>

void	centralize(t_fdf *fdf, t_point *start_p, t_point *end_p)
{
	start_p->x += fdf->cam->x_offset;
	start_p->y += fdf->cam->y_offset;
	end_p->x += fdf->cam->x_offset;
	end_p->y += fdf->cam->y_offset;
}

void	set_z_scale_factor(t_fdf *fdf)
{
	float	value;
	t_cam	*cam;

	cam = fdf->cam;
	if (fdf->map->max_z > fdf->map->min_z)
		value = fabs(fdf->map->max_z - fdf->map->min_z);
	else
		value = fabs(fdf->map->min_z - fdf->map->max_z);
	if (value >= 0 && value < 6)
		cam->z_scale_factor = 5;
	else if (value >= 6 && value < 10)
		cam->z_scale_factor = 4;
	else if (value == 10)
		cam->z_scale_factor = 1;
	else if (value > 10 && value < 20)
		cam->z_scale_factor = 3;
	else if (value >= 20 && value < 50)
		cam->z_scale_factor = 0.4;
	else if (value >= 50 && value < 100)
		cam->z_scale_factor = 0.5;
	else if (value >= 100 && value < 300)
		cam->z_scale_factor = 0.005;
	else if (value >= 300)
		cam->z_scale_factor = 0.05;
	cam->z_scale_factor += 0.000001;
}
