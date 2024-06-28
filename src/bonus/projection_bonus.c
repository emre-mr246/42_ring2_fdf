/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 03:56:07 by emgul             #+#    #+#             */
/*   Updated: 2024/06/28 21:08:09 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf_bonus.h"
#include <math.h>

static t_point	calculate_isometric(t_point *point, float z_scale_factor)
{
	t_point	new_p;

	new_p.x = (point->x - point->y) * cosf(COS_30);
	new_p.y = ((point->x + point->y) * sinf(SIN_30)) \
	- (point->z * z_scale_factor);
	return (new_p);
}

void	isometric(t_fdf *f, t_point *start_p, t_point *end_p)
{
	t_point	calculated_sp;
	t_point	calculated_ep;

	calculated_sp = calculate_isometric(start_p, f->cam->z_scale_factor);
	calculated_ep = calculate_isometric(end_p, f->cam->z_scale_factor);
	start_p->x = calculated_sp.x;
	start_p->y = calculated_sp.y;
	end_p->x = calculated_ep.x;
	end_p->y = calculated_ep.y;
}

void	oblique(t_fdf *fdf, t_point *start_p, t_point *end_p)
{
	t_point	new_start;
	t_point	new_end;
	float	scale;

	scale = 1.5;
	new_start.x = (start_p->x + 0.5 * (start_p->z \
		* -fdf->cam->z_scale_factor)) * scale * COS_30;
	new_start.y = (start_p->y + 0.5 * (start_p->z \
		* -fdf->cam->z_scale_factor)) * scale * SIN_30;
	new_end.x = (end_p->x + 0.5 * (end_p->z \
		* -fdf->cam->z_scale_factor)) * scale * COS_30;
	new_end.y = (end_p->y + 0.5 * (end_p->z \
		* -fdf->cam->z_scale_factor)) * scale * SIN_30;
	start_p->x = new_start.x;
	start_p->y = new_start.y;
	end_p->x = new_end.x;
	end_p->y = new_end.y;
}

void	perspective_top(t_fdf *fdf, t_point *start_p, t_point *end_p)
{
	start_p->x = start_p->x / (1.0 + start_p->z
			* (fdf->cam->z_scale_factor * 0.01));
	start_p->y = start_p->y / (1.0 + start_p->z
			* (fdf->cam->z_scale_factor * 0.01));
	start_p->z = 0.0;
	end_p->x = end_p->x / (1.0 + end_p->z
			* (fdf->cam->z_scale_factor * 0.01));
	end_p->y = end_p->y / (1.0 + end_p->z
			* (fdf->cam->z_scale_factor * 0.01));
	end_p->z = 0.0;
}

void	axonometric(t_point *start_p, t_point *end_p)
{
	float	previous_x;
	float	previous_y;

	previous_x = start_p->x;
	previous_y = start_p->y;
	start_p->x = (previous_x - previous_y) * cosf(0.8);
	start_p->y = -start_p->z + (previous_x + previous_y) * sinf(0.8);
	previous_x = end_p->x;
	previous_y = end_p->y;
	end_p->x = (previous_x - previous_y) * cosf(0.8);
	end_p->y = -end_p->z + (previous_x + previous_y) * sinf(0.8);
}
