/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:53:19 by emgul             #+#    #+#             */
/*   Updated: 2024/06/22 05:59:03 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/message.h"
#include "../../inc/fdf.h"
#include <X11/keysym.h>

int	handle_keypress(int key, t_fdf *fdf)
{
	if (key == XK_Escape)
		exit_with_free(MSG_EXIT, fdf);
	return (0);
}
