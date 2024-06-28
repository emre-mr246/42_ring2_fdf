/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 02:40:01 by emgul             #+#    #+#             */
/*   Updated: 2024/06/28 22:38:08 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf_bonus.h"
#include <math.h>
#include <stdlib.h>

static int	interpolate_color(t_point start, t_point end, float gradient)
{
	int	red;
	int	green;
	int	blue;

	gradient = fmaxf(0, fminf(1, gradient));
	red = (int)((1 - gradient) * ((start.color >> 16) & 0xFF) \
	+ gradient * ((end.color >> 16) & 0xFF));
	green = (int)((1 - gradient) * ((start.color >> 8) & 0xFF) \
	+ gradient * ((end.color >> 8) & 0xFF));
	blue = (int)((1 - gradient) * (start.color & 0xFF) \
	+ gradient * (end.color & 0xFF));
	red = fmaxf(0, fminf(255, red));
	green = fmaxf(0, fminf(255, green));
	blue = fmaxf(0, fminf(255, blue));
	return (create_rgb(red, green, blue));
}

static void	draw_antialiased_pixels(t_fdf *fdf, t_alg *alg, float coords[2],
		int i)
{
	int		color;

	if ((int)(coords[0]) < WIN_WIDTH)
	{
		color = interpolate_color(alg->start, alg->end, (float)(i + 1) \
		/ (float)alg->steps);
		put_pixel(fdf, (int)(coords[0]), (int)coords[1], color);
	}
}

void	draw_line_without_antialiasing(t_fdf *fdf, t_alg *alg)
{
	float	coords[2];
	int		i;
	int		color;

	coords[0] = alg->start.x;
	coords[1] = alg->start.y;
	i = 0;
	while (i <= alg->steps)
	{
		if ((int)coords[0] >= 0 && (int)coords[0] < WIN_WIDTH \
		&& (int)coords[1] >= 0 && (int)coords[1] < WIN_HEIGHT)
		{
			color = interpolate_color(alg->start, alg->end, (float)i \
			/ (float)alg->steps);
			put_pixel(fdf, (int)coords[0], (int)coords[1], color);
			draw_antialiased_pixels(fdf, alg, coords, i);
		}
		coords[0] += alg->x_incre;
		coords[1] += alg->y_incre;
		i++;
	}
}

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

void	draw(t_fdf *fdf, t_point start, t_point end)
{
	t_alg	alg;

	alg.start = start;
	alg.end = end;
	calculate_steps(&alg);
	if (fdf->cam->anti_aliasing)
		draw_line_with_antialiasing(fdf, &alg);
	else
		draw_line_without_antialiasing(fdf, &alg);
}
