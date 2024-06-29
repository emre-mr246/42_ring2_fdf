/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 03:22:57 by emgul             #+#    #+#             */
/*   Updated: 2024/06/30 02:39:15 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf_bonus.h"
#include <X11/keysym.h>

void	set_rgb(t_fdf *fdf, int *r, int *g, int *b)
{
	if (fdf->cam->color_mode == 0)
	{
		*r = (fdf->flag->low_color >> 16) & 0xFF;
		*g = (fdf->flag->low_color >> 8) & 0xFF;
		*b = fdf->flag->low_color & 0xFF;
	}
	else if (fdf->cam->color_mode == 1)
	{
		*r = (fdf->flag->mid_color >> 16) & 0xFF;
		*g = (fdf->flag->mid_color >> 8) & 0xFF;
		*b = fdf->flag->mid_color & 0xFF;
	}
	else if (fdf->cam->color_mode == 2)
	{
		*r = (fdf->flag->high_color >> 16) & 0xFF;
		*g = (fdf->flag->high_color >> 8) & 0xFF;
		*b = fdf->flag->high_color & 0xFF;
	}
}

static void	increment_rgb(t_fdf *fdf, int key)
{
	int	r;
	int	g;
	int	b;
	int	new_color;

	set_rgb(fdf, &r, &g, &b);
	if (key == XK_c)
		r = (r + 5) % 256;
	else if (key == XK_v)
		g = (g + 5) % 256;
	else if (key == XK_b)
		b = (b + 5) % 256;
	new_color = (r << 16) | (g << 8) | b;
	if (fdf->cam->color_mode == 0)
		fdf->flag->low_color = new_color;
	else if (fdf->cam->color_mode == 1)
		fdf->flag->mid_color = new_color;
	else if (fdf->cam->color_mode == 2)
		fdf->flag->high_color = new_color;
}

void	restore_color(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map->height)
	{
		j = 0;
		while (j < fdf->map->width)
		{
			fdf->map->matrix[i][j].color = fdf->map->matrix_color[i][j];
			j++;
		}
		i++;
	}
}

static void	handle_reset_color_mode(t_fdf *fdf, int key)
{
	if (key == XK_j)
	{
		if (!fdf->map->has_color)
			fdf->map->has_color = 0;
		fdf->cam->color_mode_activated = !fdf->cam->color_mode_activated;
		fdf->flag->low_color = 0;
		fdf->flag->mid_color = 0;
		fdf->flag->high_color = 0;
		handle_color_flag(fdf);
		restore_color(fdf);
	}
}

void	handle_color(t_fdf *fdf, int key)
{
	if (key == XK_n)
	{
		if (fdf->cam->color_mode == 0)
			fdf->cam->color_mode = 1;
		else if (fdf->cam->color_mode == 1)
			fdf->cam->color_mode = 2;
		else if (fdf->cam->color_mode == 2)
			fdf->cam->color_mode = 0;
	}
	if (key == XK_c || key == XK_v || key == XK_b)
	{
		increment_rgb(fdf, key);
		handle_color_flag(fdf);
	}
	if (key == XK_m)
		fdf->map->has_color = !fdf->map->has_color;
	handle_reset_color_mode(fdf, key);
}
