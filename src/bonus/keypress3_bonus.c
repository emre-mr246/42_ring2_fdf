/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress3_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:15:52 by emgul             #+#    #+#             */
/*   Updated: 2024/06/29 23:17:26 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf_bonus.h"
#include <X11/keysym.h>

void	handle_projection(t_fdf *fdf, int key)
{
	reset_cam(fdf);
	if (key == XK_1)
		fdf->cam->projection = ISOMETRIC;
	else if (key == XK_2)
		fdf->cam->projection = OBLIQUE;
	else if (key == XK_3)
		fdf->cam->projection = AXONOMETRIC;
	else if (key == XK_4)
		fdf->cam->projection = PERSPECTIVE_BOTTOM;
	else if (key == XK_5)
		fdf->cam->projection = TOP;
}
