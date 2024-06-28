/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 03:52:05 by emgul             #+#    #+#             */
/*   Updated: 2024/06/28 23:44:53 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/color_bonus.h"
#include "../../inc/fdf_bonus.h"
#include "../../lib/minilibx/mlx.h"
#include <stdlib.h>

void	show_anti_aliasing(t_fdf *fdf)
{
	int	loc;

	loc = 575;
	if (fdf->cam->anti_aliasing == 1)
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 105, loc,
			HEX_GREEN, "ON");
	else
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 105, loc,
			HEX_RED, "OFF");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, loc, HEX_WHITE,
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

static void	create_rgb_menu(int color, int *r, int *g, int *b)
{
	*r = (color >> 16) & 0xFF;
	*g = (color >> 8) & 0xFF;
	*b = color & 0xFF;
}

void	show_color(t_fdf *fdf)
{
	int		r;
	int		g;
	int		b;
	char	*str;
	int		loc;

	loc = 455;
	if (fdf->cam->color_mode == 0)
		create_rgb_menu(fdf->flag->low_color, &r, &g, &b);
	else if (fdf->cam->color_mode == 1)
		create_rgb_menu(fdf->flag->mid_color, &r, &g, &b);
	else if (fdf->cam->color_mode == 2)
		create_rgb_menu(fdf->flag->high_color, &r, &g, &b);
	str = itoa_with_prefix_suffix(r, "R: ", " [C]");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, loc, HEX_RED, str);
	free(str);
	str = itoa_with_prefix_suffix(g, "G: ", " [V]");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, loc + 15, HEX_GREEN, str);
	free(str);
	str = itoa_with_prefix_suffix(b, "B: ", " [B]");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, loc + 30, HEX_BLUE, str);
	free(str);
}

void	show_location(t_fdf *fdf)
{
	char	*coord;
	int		loc;

	loc = 400;
	coord = itoa_with_prefix_suffix(fdf->cam->x_offset - (WIN_WIDTH / 2) - 95,
			"X Offset: ", NULL);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, loc, HEX_LBLUE, coord);
	free(coord);
	coord = itoa_with_prefix_suffix((int)fdf->cam->y_offset - (WIN_HEIGHT / 2),
			"Y Offset: ", NULL);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, loc + 15, HEX_LBLUE, coord);
	free(coord);
	coord = itoa_with_prefix_suffix(fdf->cam->rotate_z * 20, "Rotate: ", NULL);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, loc + 30, HEX_LBLUE, coord);
	free(coord);
}
