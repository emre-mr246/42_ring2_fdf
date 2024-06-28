/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:25:23 by emgul             #+#    #+#             */
/*   Updated: 2024/06/28 23:44:21 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/message_bonus.h"
#include "../../inc/fdf_bonus.h"
#include "../../lib/minilibx/mlx.h"
#include <limits.h>
#include <stdlib.h>

static void	init_map(t_fdf *fdf)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		exit_with_error(ERR_MALLOC, fdf);
	map->width = 0;
	map->height = 0;
	map->max_z = INT_MIN;
	map->mid_z = 0;
	map->min_z = INT_MAX;
	map->matrix = NULL;
	map->has_color = 0;
	map->matrix_color = NULL;
	fdf->map = map;
}

static void	init_mlx(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		exit_with_error(ERR_INIT_MLX, fdf);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			WIN_NAME);
	if (!fdf->win_ptr)
		exit_with_error(ERR_INIT_MLX_WIN, fdf);
	fdf->img->ptr = mlx_new_image(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!fdf->img->ptr)
		exit_with_error(ERR_INIT_MLX_IMG, fdf);
	fdf->img->data = mlx_get_data_addr(fdf->img->ptr, &fdf->img->bits_per_pixel,
			&fdf->img->line_len, &fdf->img->endian);
}

static void	init_flag(t_fdf *fdf)
{
	t_flag	*flag;

	flag = (t_flag *)malloc(sizeof(t_flag));
	if (!flag)
		exit_with_error(ERR_MALLOC, fdf);
	flag->help = 0;
	flag->low_color = 0;
	flag->mid_color = 0;
	flag->high_color = 0;
	fdf->flag = flag;
}

static void	init_image(t_fdf *fdf)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		exit_with_error(ERR_MALLOC, fdf);
	img->ptr = NULL;
	img->data = NULL;
	img->bits_per_pixel = 0;
	img->line_len = 0;
	img->endian = 0;
	fdf->img = img;
}

t_fdf	*init_fdf(void)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		exit_with_error(ERR_MALLOC, NULL);
	fdf->cam = NULL;
	fdf->img = NULL;
	fdf->map = NULL;
	fdf->mlx_ptr = NULL;
	fdf->win_ptr = NULL;
	fdf->flag = NULL;
	fdf->map_name = NULL;
	init_flag(fdf);
	init_image(fdf);
	init_mlx(fdf);
	init_map(fdf);
	return (fdf);
}
