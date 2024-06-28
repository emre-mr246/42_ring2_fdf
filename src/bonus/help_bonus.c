/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 23:55:57 by emgul             #+#    #+#             */
/*   Updated: 2024/06/29 00:26:02 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf_bonus.h"
#include "../../lib/libft/libft.h"
#include <unistd.h>

void	print_help(void)
{
	ft_putendl_fd("Usage: ./fdf [.fdf::FILE] [-flag::FLAGS]", 1);
	ft_putendl_fd("-- ARGUMENTS --", 1);
	ft_putendl_fd("-H or --help: Print help message", 1);
	ft_putendl_fd("--low-color or -CL [0x00000000-0xFFFFFFFF]: Set low color",
		1);
	ft_putendl_fd("--mid-color or -CM [0x00000000-0xFFFFFFFF]: Set mid color",
		1);
	ft_putendl_fd("--high-color or -CH [0x00000000-0xFFFFFFFF]: Set high color",
		1);
	ft_putendl_fd("\n-- IN PROGRAM --", 1);
	ft_putendl_fd("[1]-[5]: Change view mode", 1);
	ft_putendl_fd("[Z]/[X]: Change z scale", 1);
	ft_putendl_fd("[L]: Make Flat", 1);
	ft_putendl_fd("[Arrow Keys]: Change rotation", 1);
	ft_putendl_fd("[Y]/[U]: Zoom in and zoom out", 1);
	ft_putendl_fd("[R]: Reset x/y offset and rotation ", 1);
	ft_putendl_fd("[G]/[H]: Increase/decease min z or mid z value", 1);
	ft_putendl_fd("[C]/[V]/[B]: Increase R/G/B value", 1);
	ft_putendl_fd("[N]: Change the color mode", 1);
	ft_putendl_fd("[I]: On/off anti aliasing", 1);
	ft_putendl_fd("[J]: Custom color mode off", 1);
}
