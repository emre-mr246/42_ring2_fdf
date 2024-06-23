/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 02:42:49 by emgul             #+#    #+#             */
/*   Updated: 2024/06/22 06:33:29 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include "../../lib/minilibx-linux/mlx.h"
#include "../../inc/color.h"

static void	render_line(t_fdf *fdf, t_point start_point, t_point end_point)
{
	scale_map(fdf, &start_point, &end_point);
	isometric(fdf, &start_point, &end_point);
	centralize(fdf, &start_point, &end_point);
	draw(fdf, start_point, end_point);
}

static void	render_background(t_fdf *fdf)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			color = HEX_GRAY;
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
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->ptr, 0, 0);
	return (0);
}
