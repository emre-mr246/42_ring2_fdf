/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:53:19 by emgul             #+#    #+#             */
/*   Updated: 2024/06/30 02:28:16 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf_bonus.h"
#include "../../inc/message_bonus.h"
#include <X11/keysym.h>
#include <fcntl.h>
#include <math.h>

static void	handle_cam(t_fdf *fdf, int key)
{
	if (key == XK_w)
		fdf->cam->y_offset -= 5;
	else if (key == XK_d)
		fdf->cam->x_offset += 5;
	else if (key == XK_a)
		fdf->cam->x_offset -= 5;
	else if (key == XK_s)
		fdf->cam->y_offset += 5;
	else if (key == XK_Up)
		fdf->cam->rotate_x += 0.1;
	else if (key == XK_Down)
		fdf->cam->rotate_x -= 0.1;
	else if (key == XK_Left)
		fdf->cam->rotate_y -= 0.1;
	else if (key == XK_Right)
		fdf->cam->rotate_y += 0.1;
	else if (key == XK_q)
		fdf->cam->rotate_z -= 0.05;
	else if (key == XK_e)
		fdf->cam->rotate_z += 0.05;
	else if (key == XK_l)
		fdf->cam->z_scale_factor = 0.000001;
}

static void	handle_min_and_max_z(int key, t_fdf *fdf)
{
	if (key == XK_g)
	{
		if (fdf->cam->color_mode == 0 && fdf->map->min_z_clr < fdf->map->mid_z)
			fdf->map->min_z_clr += 1;
		else if (fdf->cam->color_mode == 1 && fdf->map->mid_z < fdf->map->max_z)
			fdf->map->mid_z += 1;
	}
	else if (key == XK_h)
	{
		if (fdf->cam->color_mode == 0 && fdf->map->min_z_clr > fdf->map->min_z)
			fdf->map->min_z_clr -= 1;
		else if (fdf->cam->color_mode == 1
			&& fdf->map->mid_z > fdf->map->min_z_clr)
			fdf->map->mid_z -= 1;
	}
	handle_color_flag(fdf);
}

void	handle_z_scale(int key, t_fdf *fdf)
{
	if (key == XK_Control_L)
	{
		fdf->cam->rotate_x = 0;
		fdf->cam->rotate_y = 0;
		fdf->cam->rotate_z = 0;
		fdf->cam->rotate_mode = !fdf->cam->rotate_mode;
	}
	if (key == XK_z)
		fdf->cam->z_scale_factor += fdf->cam->z_scale_factor_keypress;
	else if (key == XK_x)
		fdf->cam->z_scale_factor -= fdf->cam->z_scale_factor_keypress;
}

int	handle_keypress(int key, t_fdf *fdf)
{
	if (key == XK_Escape)
		exit_with_free(MSG_EXIT, fdf);
	if (key == XK_z || key == XK_x || key == XK_Control_L)
		handle_z_scale(key, fdf);
	else if (key == XK_y)
		fdf->cam->scale += fdf->cam->scale * 0.1;
	else if (key == XK_u)
		fdf->cam->scale -= fdf->cam->scale * 0.1;
	else if (key == XK_r)
		reset_cam(fdf);
	else if (key == XK_i)
		fdf->cam->anti_aliasing = !fdf->cam->anti_aliasing;
	if (key == XK_g || key == XK_h || key == XK_c || key == XK_v || key == XK_b
		|| key == XK_n || key == XK_j || key == XK_m)
	{
		fdf->cam->color_mode_activated = 1;
		handle_min_and_max_z(key, fdf);
		handle_color(fdf, key);
	}
	if (key == XK_1 || key == XK_2 || key == XK_3 || key == XK_4 || key == XK_5)
		handle_projection(fdf, key);
	handle_cam(fdf, key);
	return (0);
}
