/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:25:44 by emgul             #+#    #+#             */
/*   Updated: 2024/06/30 02:24:51 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf_bonus.h"
#include "../../inc/message_bonus.h"
#include <stdlib.h>

void	init_cam(t_fdf *fdf)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (!cam)
		exit_with_error(ERR_MALLOC, fdf);
	cam->scale = get_scale_factor(fdf->map);
	cam->x_offset = (WIN_WIDTH / 2) + MENU_WIDTH / 2;
	cam->y_offset = (WIN_HEIGHT / 2);
	cam->z_scale_factor = 1;
	cam->z_scale_factor_keypress;
	cam->projection = ISOMETRIC;
	cam->rotate_x = 0;
	cam->rotate_y = 0;
	cam->rotate_z = 0;
	cam->color_mode = 0;
	cam->rotate_mode = 1;
	cam->color_mode_activated = 0;
	cam->anti_aliasing = 0;
	fdf->cam = cam;
	set_z_scale_factor(fdf);
	cam->z_scale_factor_keypress = cam->z_scale_factor * 0.2;
}

void	init_matrix(t_fdf *fdf, t_map *map)
{
	t_point	**matrix;
	int		x;
	int		y;

	matrix = (t_point **)malloc(map->height * sizeof(t_point *));
	if (!matrix)
		exit_with_error(ERR_MALLOC, fdf);
	x = 0;
	while (x < map->height)
	{
		matrix[x] = (t_point *)malloc(map->width * sizeof(t_point));
		if (!matrix[x])
			exit_with_error(ERR_MALLOC, fdf);
		y = 0;
		while (y < map->width)
		{
			matrix[x][y].x = 0;
			matrix[x][y].y = 0;
			matrix[x][y].z = 0;
			matrix[x][y].color = 0;
			y++;
		}
		x++;
	}
	map->matrix = matrix;
}

void	init_matrix_color(t_fdf *fdf, t_map *map)
{
	int	**matrix_color;
	int	x;
	int	y;

	matrix_color = (int **)malloc(map->height * sizeof(int *));
	if (!matrix_color)
		exit_with_error(ERR_MALLOC, fdf);
	x = 0;
	while (x < map->height)
	{
		matrix_color[x] = (int *)malloc(map->width * sizeof(int));
		if (!matrix_color[x])
			exit_with_error(ERR_MALLOC, fdf);
		y = 0;
		while (y < map->width)
		{
			matrix_color[x][y] = 0;
			y++;
		}
		x++;
	}
	map->matrix_color = matrix_color;
}
