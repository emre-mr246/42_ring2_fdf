/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 02:14:28 by emgul             #+#    #+#             */
/*   Updated: 2024/06/29 00:41:04 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf_bonus.h"
#include "../../lib/minilibx/mlx.h"
#include <stdlib.h>

static void	free_matrix(t_point **matrix, int height)
{
	t_point	**row;

	if (!matrix)
		return ;
	row = matrix;
	while (height--)
	{
		free(*row);
		row++;
	}
	free(matrix);
}

static void	free_color_matrix(int **matrix, int height)
{
	int	**row;

	if (!matrix)
		return ;
	row = matrix;
	while (height--)
	{
		free(*row);
		row++;
	}
	free(matrix);
}

void	free_split(char **split_line)
{
	char	**tmp;

	if (!split_line)
		return ;
	tmp = split_line;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(split_line);
}

static void	free_mlx(t_fdf *fdf)
{
	if (fdf->img)
	{
		if (fdf->img->ptr)
			mlx_destroy_image(fdf->mlx_ptr, fdf->img->ptr);
		free(fdf->img);
	}
	if (fdf->win_ptr)
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	if (fdf->mlx_ptr)
	{
		mlx_destroy_display(fdf->mlx_ptr);
		free(fdf->mlx_ptr);
	}
}

void	free_all(t_fdf *fdf)
{
	if (!fdf)
		return ;
	if (fdf->flag)
		free(fdf->flag);
	if (fdf->map)
	{
		if (fdf->map->matrix)
			free_matrix(fdf->map->matrix, fdf->map->height);
		if (fdf->map->matrix_color)
			free_color_matrix(fdf->map->matrix_color, fdf->map->height);
		free(fdf->map);
	}
	free_mlx(fdf);
	if (fdf->cam)
		free(fdf->cam);
	if (fdf->map_name)
		free(fdf->map_name);
	if (fdf)
		free(fdf);
}
