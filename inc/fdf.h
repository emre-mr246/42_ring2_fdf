/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:25:39 by emgul             #+#    #+#             */
/*   Updated: 2024/06/29 21:16:24 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_NAME "FDF - emgul"
# define WIN_WIDTH 1080
# define WIN_HEIGHT 720
# define MENU_WIDTH 190

# define COS_30 0.86602540378
# define SIN_30 0.5
# define PI 3.141592653589793
# define HEX_BASE 16

typedef struct s_point
{
	float			x;
	float			y;
	float			z;
	int				color;
}					t_point;

typedef struct s_img
{
	void			*ptr;
	char			*data;
	int				bits_per_pixel;
	int				line_len;
	int				endian;
}					t_img;

typedef struct s_map
{
	int				width;
	int				height;
	int				has_color;
	float			max_z;
	float			min_z;
	t_point			**matrix;
}					t_map;

typedef struct s_cam
{
	float			scale;
	float			x_offset;
	float			y_offset;
	float			z_scale_factor;
}					t_cam;

typedef struct s_alg
{
	t_point			start;
	t_point			end;
	int				steps;
	float			x_incre;
	float			y_incre;
}					t_alg;

typedef struct s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*map_name;
	struct s_flag	*flag;
	struct s_img	*img;
	struct s_map	*map;
	struct s_cam	*cam;
}					t_fdf;

// MAP | MAP UTILS
void				create_map(t_fdf *fdf);
void				scale_map(t_fdf *fdf, t_point *start_point,
						t_point *end_point);
int					get_height(char *map_name, t_fdf *fdf);
int					valid_width(int file_descriptor, int width);
void				handle_color_for_height(t_fdf *fdf);

// EXIT
void				exit_with_error(char *error_msg, t_fdf *fdf);
void				exit_with_free(char *error_msg, t_fdf *fdf);
int					exit_mlx(void *fdf);

// UTILS
int					ft_atoi_base(const char *str, int str_base);
void				put_pixel(t_fdf *fdf, int x, int y, int color);
float				get_scale_factor(t_map *map);
int					create_rgb(int red, int green, int blue);

// PARAMETERS
void				handle_parameters(t_fdf *fdf, char **argv);

// RENDER
int					render(t_fdf *fdf);

// INIT
t_fdf				*init_fdf(void);
void				init_cam(t_fdf *fdf);
void				init_matrix(t_fdf *fdf, t_map *map);

// FREE
void				free_all(t_fdf *fdf);
void				free_split(char **split_line);

// DRAW
void				draw(t_fdf *fdf, t_point start, t_point end);

// MATRIX
void				get_matrix(t_fdf *fdf);

// KEYPRESS
int					handle_keypress(int key, t_fdf *fdf);

// PROJECTION
void				isometric(t_fdf *f, t_point *sp, t_point *ep);

// CAM
void				set_z_scale_factor(t_fdf *fdf);
void				centralize(t_fdf *fdf, t_point *initial_point,
						t_point *end_point);
#endif