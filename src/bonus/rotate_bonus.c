/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:36:38 by emgul             #+#    #+#             */
/*   Updated: 2024/06/28 21:08:16 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf_bonus.h"
#include <math.h>

static void	calculate_trig(float angle, float *cos_ang, float *sin_ang)
{
	*cos_ang = cosf(angle);
	*sin_ang = sinf(angle);
}

void	rotate_x(t_fdf *fdf, t_point *start_p, t_point *end_p, float angle)
{
	t_rotate	r;
	float		z_scale;

	z_scale = fdf->cam->z_scale_factor;
	calculate_trig(angle, &r.cos_ang, &r.sin_ang);
	r.sy = start_p->y;
	r.sz = start_p->z * z_scale;
	r.ey = end_p->y;
	r.ez = end_p->z * z_scale;
	start_p->y = (r.sy * r.cos_ang) - (r.sz * r.sin_ang);
	start_p->z = (r.sy * r.sin_ang) + ((r.sz * r.cos_ang) / z_scale);
	end_p->y = (r.ey * r.cos_ang) - (r.ez * r.sin_ang);
	end_p->z = (r.ey * r.sin_ang) + ((r.ez * r.cos_ang) / z_scale);
}

void	rotate_y(t_point *start_p, t_point *end_p, float angle)
{
	t_rotate	r;

	calculate_trig(angle, &r.cos_ang, &r.sin_ang);
	r.sx = start_p->x;
	r.sz = start_p->z;
	r.ex = end_p->x;
	r.ez = end_p->z;
	start_p->x = (r.sx * r.cos_ang) + (r.sz * r.sin_ang);
	start_p->z = (-r.sx * r.sin_ang) + (r.sz * r.cos_ang);
	end_p->x = (r.ex * r.cos_ang) + (r.ez * r.sin_ang);
	end_p->z = (-r.ex * r.sin_ang) + (r.ez * r.cos_ang);
}

void	rotate_z(t_point *start_p, t_point *end_p, float angle)
{
	t_rotate	r;

	calculate_trig(angle, &r.cos_ang, &r.sin_ang);
	r.sx = start_p->x;
	r.sy = start_p->y;
	r.ex = end_p->x;
	r.ey = end_p->y;
	start_p->x = (r.sx * r.cos_ang) - (r.sy * r.sin_ang);
	start_p->y = (r.sx * r.sin_ang) + (r.sy * r.cos_ang);
	end_p->x = (r.ex * r.cos_ang) - (r.ey * r.sin_ang);
	end_p->y = (r.ex * r.sin_ang) + (r.ey * r.cos_ang);
}
