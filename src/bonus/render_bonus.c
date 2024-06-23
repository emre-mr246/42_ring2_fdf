/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 02:42:49 by emgul             #+#    #+#             */
/*   Updated: 2024/06/23 19:53:47 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/color.h"
#include "../../inc/fdf.h"
#include "../../lib/minilibx/mlx.h"

static void	render_line(t_fdf *fdf, t_point start_point, t_point end_point)
{
	scale_map(fdf, &start_point, &end_point);
	if (fdf->cam->projection == ISOMETRIC)
		isometric(fdf, &start_point, &end_point);
	else if (fdf->cam->projection == OBLIQUE)
		oblique(fdf, &start_point, &end_point);
	else if (fdf->cam->projection == AXONOMETRIC)
		axonometric(&start_point, &end_point);
	else if (fdf->cam->projection == PERSPECTIVE_TOP)
		perspective_top(fdf, &start_point, &end_point);
	rotate_x(fdf, &start_point, &end_point, fdf->cam->rotate_x);
	rotate_y(&start_point, &end_point, fdf->cam->rotate_y);
	rotate_z(&start_point, &end_point, fdf->cam->rotate_z);
	centralize(fdf, &start_point, &end_point);
	draw(fdf, start_point, end_point);
}

static void	render_border(t_fdf *fdf)
{
	unsigned int	y;
	unsigned int	x;

	if (fdf->win_ptr)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			x = 0;
			while (x < WIN_WIDTH)
			{
				if (x < 10 || x >= WIN_WIDTH - 10 || y < 10 || y >= WIN_HEIGHT
					- 10)
					put_pixel(fdf, x, y, HEX_BORDER_CLR);
				x++;
			}
			y++;
		}
	}
}

static int	calculate_background_color(int x, int y)
{
	int	r;
	int	g;
	int	b;

	r = (x * 255) / WIN_WIDTH;
	g = (y * 255) / WIN_HEIGHT;
	b = 100;
	return ((r << 16) | (g << 8) | b);
}

static void	render_background(t_fdf *fdf)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = MENU_WIDTH;
		while (x < WIN_WIDTH)
		{
			color = calculate_background_color(x, y);
			put_pixel(fdf, x, y, color);
			x++;
		}
		y++;
	}
}

int	render(t_fdf *fdf)
{
	int		x;
	int		y;
	t_map	*map;
	t_point	**matrix;

	map = fdf->map;
	matrix = map->matrix;
	render_background(fdf);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (x < map->width - 1)
				render_line(fdf, matrix[y][x], matrix[y][x + 1]);
			if (y < map->height - 1)
				render_line(fdf, matrix[y][x], matrix[y + 1][x]);
		}
	}
	render_border(fdf);
	render_menu_bar(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->ptr, 0, 0);
	render_menu(fdf);
	return (0);
}
