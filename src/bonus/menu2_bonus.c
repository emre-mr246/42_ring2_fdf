/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 03:52:05 by emgul             #+#    #+#             */
/*   Updated: 2024/06/21 23:27:26 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/color.h"
#include "../../inc/fdf.h"
#include "../../lib/minilibx-linux/mlx.h"
#include <stdlib.h>

void	show_color_mode(t_fdf *fdf)
{
	char	*str;

	str = NULL;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, 500, HEX_WHITE,
		"Color Mode: ");
	if (fdf->cam->color_mode == 0)
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 90, 500, HEX_GREEN, "Low");
	else
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 90, 500, HEX_RED, "High");
	str = itoa_with_prefix_suffix((int)fdf->map->min_z_clr, "Min Z: ",
			" [G][H]");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, 525, HEX_CYAN, str);
	free(str);
	str = itoa_with_prefix_suffix((int)fdf->map->max_z, "Max Z: ", NULL);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, 540, HEX_CYAN, str);
	free(str);
}

void	show_anti_aliasing(t_fdf *fdf)
{
	if (fdf->cam->anti_aliasing == 1)
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 105, 565,
			HEX_GREEN, "ON");
	else
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 105, 565,
			HEX_RED, "OFF");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, 565, HEX_WHITE,
		"Anti-Aliasing: ");
}

void	show_move(t_fdf *fdf)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		loc;

	loc = WIN_HEIGHT - 130;
	mlx_ptr = fdf->mlx_ptr;
	win_ptr = fdf->win_ptr;
	mlx_string_put(mlx_ptr, win_ptr, 70, loc, HEX_ORANGE, " ____");
	mlx_string_put(mlx_ptr, win_ptr, 70, loc + 10, HEX_ORANGE, "||W ||");
	mlx_string_put(mlx_ptr, win_ptr, 70, loc + 20, HEX_ORANGE, "||__||");
	mlx_string_put(mlx_ptr, win_ptr, 70, loc + 30, HEX_ORANGE, "|/__\\|");
	mlx_string_put(mlx_ptr, win_ptr, 42, loc + 40, HEX_ORANGE,
		" ____ ____ ____ ");
	mlx_string_put(mlx_ptr, win_ptr, 42, loc + 50, HEX_ORANGE, \
	"||A |||S|||D||");
	mlx_string_put(mlx_ptr, win_ptr, 42, loc + 60, HEX_ORANGE,
		"||__|||__|||__||");
	mlx_string_put(mlx_ptr, win_ptr, 42, loc + 70, HEX_ORANGE,
		"|/__\\|/__\\|/__\\|");
	mlx_string_put(mlx_ptr, win_ptr, 20, loc + 90, HEX_PURPLE, \
	"Move [WASD] / Rotate [QE]");
}

void	show_color(t_fdf *fdf)
{
	t_rgb	rgb;

	if (fdf->cam->color_mode == 0)
	{
		rgb.r = (fdf->flag->low_color >> 16) & 0xFF;
		rgb.g = (fdf->flag->low_color >> 8) & 0xFF;
		rgb.b = fdf->flag->low_color & 0xFF;
	}
	else
	{
		rgb.r = (fdf->flag->high_color >> 16) & 0xFF;
		rgb.g = (fdf->flag->high_color >> 8) & 0xFF;
		rgb.b = fdf->flag->high_color & 0xFF;
	}
	rgb.color = itoa_with_prefix_suffix(rgb.r, "R: ", " [C]");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, 455, HEX_RED, rgb.color);
	free(rgb.color);
	rgb.color = itoa_with_prefix_suffix(rgb.g, "G: ", " [V]");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, 470, HEX_GREEN, rgb.color);
	free(rgb.color);
	rgb.color = itoa_with_prefix_suffix(rgb.b, "B: ", " [B]");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, 485, HEX_BLUE, rgb.color);
	free(rgb.color);
}

void	show_location(t_fdf *fdf)
{
	char	*coord;

	coord = itoa_with_prefix_suffix(fdf->cam->x_offset - (WIN_WIDTH / 2) - 90,
			"X Offset: ", NULL);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, 400, HEX_LBLUE, coord);
	free(coord);
	coord = itoa_with_prefix_suffix((int)fdf->cam->y_offset - (WIN_HEIGHT / 2),
			"Y Offset: ", NULL);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, 415, HEX_LBLUE, coord);
	free(coord);
	coord = itoa_with_prefix_suffix(fdf->cam->rotate_z * 20, "Rotate: ", NULL);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, 430, HEX_LBLUE, coord);
	free(coord);
}
