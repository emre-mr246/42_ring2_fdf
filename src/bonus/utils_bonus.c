/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 02:37:07 by emgul             #+#    #+#             */
/*   Updated: 2024/06/29 04:56:31 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/message_bonus.h"
#include "../../inc/fdf_bonus.h"
#include "../../lib/libft/libft.h"

float	get_scale_factor(t_map *map)
{
	float	scale_factor;
	float	scale_x;
	float	scale_y;

	scale_x = (float)WIN_WIDTH / (float)map->width;
	scale_y = (float)WIN_HEIGHT / (float)map->height;
	if (scale_x < scale_y)
		scale_factor = scale_x;
	else
		scale_factor = scale_y;
	if (scale_factor < 3)
		return (scale_factor);
	return (scale_factor / 1.2);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	res = 0;
	while (str[i])
	{
		res *= str_base;
		if (str[i] >= '0' && str[i] <= '9')
			res += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			res += str[i] - '7';
		else if (str[i] >= 'a' && str[i] <= 'z')
			res += str[i] - 'W';
		i++;
	}
	return (res * sign);
}

char	*itoa_with_prefix_suffix(int i, char *prefix, char *suffix)
{
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = NULL;
	str = ft_itoa(i);
	if (!str)
		return (NULL);
	if (prefix)
	{
		tmp = str;
		str = ft_strjoin(prefix, str);
		free(tmp);
	}
	if (suffix)
	{
		tmp = str;
		str = ft_strjoin(str, suffix);
		free(tmp);
	}
	return (str);
}

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*pixel;
	int		bytes_per_pixel;

	bytes_per_pixel = fdf->img->bits_per_pixel / 8;
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		exit_with_error(ERR_COORD, fdf);
	pixel = fdf->img->data + (y * fdf->img->line_len) + (x * bytes_per_pixel);
	*(unsigned int *)pixel = color;
}

int	create_rgb(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}
