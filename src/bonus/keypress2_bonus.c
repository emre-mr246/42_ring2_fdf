/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 03:22:57 by emgul             #+#    #+#             */
/*   Updated: 2024/06/21 22:43:44 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include <X11/keysym.h>

void	set_rgb(t_fdf *fdf, int *r, int *g, int *b)
{
	if (fdf->cam->color_mode == 0)
	{
		*r = (fdf->flag->low_color >> 16) & 0xFF;
		*g = (fdf->flag->low_color >> 8) & 0xFF;
		*b = fdf->flag->low_color & 0xFF;
	}
	else
	{
		*r = (fdf->flag->high_color >> 16) & 0xFF;
		*g = (fdf->flag->high_color >> 8) & 0xFF;
		*b = fdf->flag->high_color & 0xFF;
	}
}

static void	increment_rgb(t_fdf *fdf, int key)
{
	t_rgb	rgb;

	set_rgb(fdf, &rgb.r, &rgb.g, &rgb.b);
	if (key == XK_c)
	{
		rgb.r += 5;
		if (rgb.r > 255)
			rgb.r = 0;
	}
	else if (key == XK_v)
	{
		rgb.g += 5;
		if (rgb.g > 255)
			rgb.g = 0;
	}
	else if (key == XK_b)
	{
		rgb.b += 5;
		if (rgb.b > 255)
			rgb.b = 0;
	}
	if (fdf->cam->color_mode == 0)
		fdf->flag->low_color = (rgb.r << 16) | (rgb.g << 8) | rgb.b;
	else
		fdf->flag->high_color = (rgb.r << 16) | (rgb.g << 8) | rgb.b;
}

void	handle_color(t_fdf *fdf, int key)
{
	if (key == XK_n)
		fdf->cam->color_mode = !fdf->cam->color_mode;
	if (key == XK_c || key == XK_v || key == XK_b)
	{
		increment_rgb(fdf, key);
		handle_color_flag(fdf);
	}
}
