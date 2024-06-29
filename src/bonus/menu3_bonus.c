/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu3_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 22:49:52 by emgul             #+#    #+#             */
/*   Updated: 2024/06/30 00:01:29 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/color_bonus.h"
#include "../../inc/fdf_bonus.h"
#include "../../lib/minilibx/mlx.h"
#include <stdlib.h>

void	set_color_mode(t_fdf *fdf)
{
	int	loc;

	loc = 500;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, loc, HEX_WHITE,
		"Color Mode: ");
	if (fdf->cam->color_mode == 0)
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 90, loc, HEX_GREEN, "Low");
	else if (fdf->cam->color_mode == 1)
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 90, loc, HEX_BLUE, "Medium");
	else if (fdf->cam->color_mode == 2)
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 90, loc, HEX_RED, "High");
}

void	display_color_mode_status(t_fdf *fdf, int y)
{
	if (fdf->cam->color_mode_activated)
	{
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 142, y, HEX_RED, "[C");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 155, y, HEX_GREEN, "L");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 163, y, HEX_BLUE, "R]");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 150, y + 15, HEX_GREEN,
			"[J]");
	}
}

void	show_color_mode(t_fdf *fdf)
{
	char	*str;
	int		loc;

	loc = 500;
	str = itoa_with_prefix_suffix((int)fdf->map->min_z_clr, "Min Z: ",
			" [G][H]");
	set_color_mode(fdf);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, loc + 25, HEX_CYAN, str);
	free(str);
	str = itoa_with_prefix_suffix((int)fdf->map->mid_z, "Mid Z: ", " [G][H]");
	set_color_mode(fdf);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, loc + 40, HEX_CYAN, str);
	free(str);
	str = itoa_with_prefix_suffix((int)fdf->map->max_z, "Max Z: ", NULL);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, loc + 55, HEX_CYAN, str);
	display_color_mode_status(fdf, loc - 45);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, loc + 75, HEX_GREEN, \
	"Height Based Mode - [M]");
	if (!fdf->map->has_color)
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 160, loc + 75, HEX_PRED, \
		"+");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, loc + 90, HEX_ORANGE, \
	"Color Mode Off - [J]");
	free(str);
}

void	show_rotate_mode(t_fdf *fdf)
{
	int	loc;

	loc = 545;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18, loc + 70, HEX_WHITE,
		"Rotate Mode: ");
	if (fdf->cam->rotate_mode == 0)
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 95, loc + 70, HEX_RED, \
		"Camera [LCtrl]");
	else if (fdf->cam->rotate_mode == 1)
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 95, loc + 70, HEX_GREEN,
			"Axis [LCtrl]");
}
