/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 02:40:01 by emgul             #+#    #+#             */
/*   Updated: 2024/06/22 05:55:01 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include <math.h>
#include <stdlib.h>

static void	calculate_steps(t_alg *alg)
{
	float	dx;
	float	dy;

	dx = alg->end.x - alg->start.x;
	dy = alg->end.y - alg->start.y;
	if (abs((int)dx) > abs((int)dy))
		alg->steps = abs((int)dx);
	else
		alg->steps = abs((int)dy);
	alg->x_incre = dx / (float)alg->steps;
	alg->y_incre = dy / (float)alg->steps;
}

static void	draw_line_without_antialiasing(t_fdf *fdf, t_alg *alg)
{
	float	coords[2];
	int		i;

	coords[0] = alg->start.x;
	coords[1] = alg->start.y;
	i = 0;
	while (i <= alg->steps)
	{
		if ((int)coords[0] >= 0 && (int)coords[0] < WIN_WIDTH
			&& (int)coords[1] >= 0 && (int)coords[1] < WIN_HEIGHT)
		{
			put_pixel(fdf, (int)coords[0], (int)coords[1], alg->start.color);
		}
		coords[0] += alg->x_incre;
		coords[1] += alg->y_incre;
		i++;
	}
}

void	draw(t_fdf *fdf, t_point start, t_point end)
{
	t_alg	alg;

	alg.start = start;
	alg.end = end;
	calculate_steps(&alg);
	draw_line_without_antialiasing(fdf, &alg);
}
