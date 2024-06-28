/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:14:31 by emgul             #+#    #+#             */
/*   Updated: 2024/06/28 23:57:08 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/message_bonus.h"
#include "../../inc/fdf_bonus.h"
#include "../../lib/libft/libft.h"

void	exit_with_error(char *error_msg, t_fdf *fdf)
{
	ft_putendl_fd(error_msg, 2);
	if (fdf)
		free_all(fdf);
	exit(EXIT_FAILURE);
}

void	exit_with_free(char *exit_msg, t_fdf *fdf)
{
	if (exit_msg)
		ft_putendl_fd(exit_msg, 1);
	if (fdf)
		free_all(fdf);
	exit(EXIT_SUCCESS);
}

int	exit_mlx(void *fdf)
{
	ft_putendl_fd(MSG_EXIT, 1);
	if (fdf)
		free_all(fdf);
	exit(EXIT_SUCCESS);
}
