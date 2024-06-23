/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 05:12:06 by emgul             #+#    #+#             */
/*   Updated: 2024/06/22 05:55:01 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include <math.h>
#include <stdlib.h>

static int	create_rgb(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

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

	if ((int)(coords[0] + 1) < WIN_WIDTH)
	{
		color = interpolate_color(alg->start, alg->end, (float)(i + 1) \
		/ (float)alg->steps);
		put_pixel(fdf, (int)(coords[0] + 1), (int)coords[1], color);
	}
	if ((int)(coords[1] + 1) < WIN_HEIGHT)
	{
		color = interpolate_color(alg->start, alg->end, (float)(i + 1) \
		/ (float)alg->steps);
		put_pixel(fdf, (int)coords[0], (int)(coords[1] + 1), color);
	}
	if ((int)(coords[0] + 1) < WIN_WIDTH && (int)(coords[1] + 1) < WIN_HEIGHT)
	{
		color = interpolate_color(alg->start, alg->end, (float)(i + 1) \
		/ (float)alg->steps);
		put_pixel(fdf, (int)(coords[0] + 1), (int)(coords[1] + 1), color);
	}
}

void	draw_line_with_antialiasing(t_fdf *fdf, t_alg *alg)
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
