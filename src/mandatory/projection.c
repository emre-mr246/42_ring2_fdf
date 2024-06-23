/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 03:56:07 by emgul             #+#    #+#             */
/*   Updated: 2024/06/21 05:53:31 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include <math.h>

static t_point	calculate_isometric(t_point *p, float z_scale_factor)
{
	t_point	new_p;

	new_p.x = (p->x - p->y) * cosf(COS_30);
	new_p.y = (p->x + p->y) * sinf(SIN_30) - p->z * z_scale_factor;
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
