/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 08:42:24 by emgul             #+#    #+#             */
/*   Updated: 2024/06/22 05:58:47 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/message.h"
#include "../../inc/fdf.h"
#include "../../lib/libft/libft.h"

static int	is_hex(char *str)
{
	if (!str || !*str)
		return (0);
	if (ft_strlen(str) != 8)
		return (0);
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		str += 2;
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'f')
			|| (*str >= 'A' && *str <= 'F'))
			str++;
		else
			return (0);
	}
	return (1);
}

static void	check_parameters(char **argv, t_fdf *fdf)
{
	while (*argv)
	{
		if (ft_strncmp(*argv, "--help", 7) == 0 || ft_strncmp(*argv, "-H",
				2) == 0)
		{
			fdf->flag->help = 1;
			return ;
		}
		else if ((ft_strncmp(*argv, "--low-color", 11) == 0 || ft_strncmp(*argv,
					"-CL", 3) == 0) && is_hex(*(argv + 1)))
			fdf->flag->low_color = ft_atoi_base(*(++argv) + 2, HEX_BASE);
		else if ((ft_strncmp(*argv, "--high-color", 12) == 0
				|| ft_strncmp(*argv, "-CH", 3) == 0) && is_hex(*(argv + 1)))
			fdf->flag->high_color = ft_atoi_base(*(++argv) + 2, HEX_BASE);
		else if (ft_strncmp(*argv + (ft_strlen(*argv) - 4), ".fdf", 4) == 0)
			fdf->map_name = ft_strdup(*argv);
		else if (!is_hex(*argv))
			exit_with_error(ERR_FLAG, fdf);
		argv++;
	}
}

void	handle_parameters(t_fdf *fdf, char **argv)
{
	argv++;
	check_parameters(argv, fdf);
	while (*argv)
	{
		if (fdf->flag->help == 1)
			exit_with_free(MSG_HELP, fdf);
		argv++;
	}
}
