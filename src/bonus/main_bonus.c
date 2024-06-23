/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:21:54 by emgul             #+#    #+#             */
/*   Updated: 2024/06/23 19:53:36 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/message.h"
#include "../../inc/fdf.h"
#include "../../lib/minilibx/mlx.h"
#include <X11/X.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc <= 1 || argc > 7)
		exit_with_error(ERR_ARG, NULL);
	if (WIN_WIDTH < 1080 || WIN_HEIGHT < 720 || WIN_WIDTH > 2560
		|| WIN_HEIGHT > 1440)
		exit_with_error(ERR_WIN_SIZE, NULL);
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
