/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:21:54 by emgul             #+#    #+#             */
/*   Updated: 2024/06/22 05:59:06 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/message.h"
#include "../../inc/fdf.h"
#include "../../lib/minilibx-linux/mlx.h"
#include <X11/X.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		exit_with_error(ERR_ARG, NULL);
	fdf = init_fdf();
	handle_parameters(fdf, argv);
	create_map(fdf);
	init_cam(fdf);
	mlx_loop_hook(fdf->mlx_ptr, &render, fdf);
	mlx_hook(fdf->win_ptr, KeyPress, KeyPressMask, handle_keypress, fdf);
	mlx_hook(fdf->win_ptr, DestroyNotify, KeyReleaseMask, exit_mlx, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
