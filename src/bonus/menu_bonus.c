/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 02:41:53 by emgul             #+#    #+#             */
/*   Updated: 2024/06/23 19:53:41 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/color.h"
#include "../../inc/fdf.h"
#include "../../lib/minilibx/mlx.h"
#include "../../lib/libft/libft.h"

void	show_projections(t_fdf *fdf)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = fdf->mlx_ptr;
	win_ptr = fdf->win_ptr;
	mlx_string_put(mlx_ptr, win_ptr, 18, 110, HEX_CYAN, " - VIEW -");
	mlx_string_put(mlx_ptr, win_ptr, 18, 125, HEX_LIME, "[1] isometric");
	mlx_string_put(mlx_ptr, win_ptr, 18, 140, HEX_LIME, "[2] oblique");
	mlx_string_put(mlx_ptr, win_ptr, 18, 155, HEX_LIME, "[3] axonometric");
	mlx_string_put(mlx_ptr, win_ptr, 18, 170, HEX_LIME,
		"[4] perspective top view");
	mlx_string_put(mlx_ptr, win_ptr, 18, 185, HEX_LIME, "[5] top view");
}

void	show_fdf_ascii_art(t_fdf *fdf)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = fdf->mlx_ptr;
	win_ptr = fdf->win_ptr;
	mlx_string_put(mlx_ptr, win_ptr, 28, 30, HEX_BLUE, \
	"    __________  ______");
	mlx_string_put(mlx_ptr, win_ptr, 28, 40, HEX_BLUE, \
	"   / ____/ __ \\/ ____/");
	mlx_string_put(mlx_ptr, win_ptr, 28, 50, HEX_BLUE, \
	"  / /_  / / / //_");
	mlx_string_put(mlx_ptr, win_ptr, 28, 60, HEX_BLUE, \
	" / __/ / /_// __/");
	mlx_string_put(mlx_ptr, win_ptr, 28, 70, HEX_BLUE, \
	"/_/  /_____/_/");
	mlx_string_put(mlx_ptr, win_ptr, 23, 85, HEX_LBLUE, \
	"_________________________");
}

void	show_instructions(t_fdf *fdf)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = fdf->mlx_ptr;
	win_ptr = fdf->win_ptr;
	mlx_string_put(mlx_ptr, win_ptr, 18, 210, HEX_YELLOW, \
	"Increase Scale Z - [Z]");
	mlx_string_put(mlx_ptr, win_ptr, 18, 225, HEX_YELLOW, \
	"Decrease Scale Z - [X]");
	mlx_string_put(mlx_ptr, win_ptr, 18, 240, HEX_YELLOW, \
	"Make Flat [L]");
	mlx_string_put(mlx_ptr, win_ptr, 18, 265, HEX_ORANGE, \
	"Rotate Up - [Up Arrow]");
	mlx_string_put(mlx_ptr, win_ptr, 18, 280, HEX_ORANGE, \
	"Rotate Down - [Down A.]");
	mlx_string_put(mlx_ptr, win_ptr, 18, 295, HEX_ORANGE, \
	"Rotate Left - [Left A.]");
	mlx_string_put(mlx_ptr, win_ptr, 18, 310, HEX_ORANGE, \
	"Rotate Right - [Right A.]");
	mlx_string_put(mlx_ptr, win_ptr, 18, 335, HEX_PRED, "Zoom In - [Y]");
	mlx_string_put(mlx_ptr, win_ptr, 18, 350, HEX_PRED, "Zoom Out - [U]");
	mlx_string_put(mlx_ptr, win_ptr, 18, 375, HEX_PURPLE, "Reset Cam - [R]");
}

void	render_menu(t_fdf *fdf)
{
	show_fdf_ascii_art(fdf);
	show_projections(fdf);
	show_instructions(fdf);
	show_location(fdf);
	show_color(fdf);
	show_color_mode(fdf);
	show_move(fdf);
	show_anti_aliasing(fdf);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 25, WIN_HEIGHT - 20, HEX_GREEN, \
	"- Press [ESC] to exit -");
}

void	render_menu_bar(t_fdf *fdf)
{
	int	y;
	int	x;

	if (fdf->win_ptr)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			x = 0;
			while (x < MENU_WIDTH)
			{
				if (x < 10 || x >= MENU_WIDTH - 10 || y < 10 \
				|| y >= WIN_HEIGHT - 10)
					put_pixel(fdf, x, y, 0x010101);
				else
					put_pixel(fdf, x, y, 0x181818);
				x++;
			}
			y++;
		}
	}
}
