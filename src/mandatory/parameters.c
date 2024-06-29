/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 08:42:24 by emgul             #+#    #+#             */
/*   Updated: 2024/06/29 01:57:19 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/message.h"
#include "../../inc/fdf.h"
#include "../../lib/libft/libft.h"

static void	check_parameters(char **argv, t_fdf *fdf)
{
	while (*argv)
	{
		if (ft_strncmp(*argv + (ft_strlen(*argv) - 4), ".fdf", 4) == 0)
			fdf->map_name = ft_strdup(*argv);
		else
			exit_with_error(ERR_FLAG, fdf);
		argv++;
	}
}

void	handle_parameters(t_fdf *fdf, char **argv)
{
	argv++;
	check_parameters(argv, fdf);
}
