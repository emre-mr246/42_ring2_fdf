/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:25:39 by emgul             #+#    #+#             */
/*   Updated: 2024/06/29 00:35:38 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# define WIN_NAME "FDF BONUS - emgul"
# define WIN_WIDTH 1080
# define WIN_HEIGHT 720
# define MENU_WIDTH 190

# define COS_30 0.866
# define SIN_30 0.5
# define PI 3.141592653589793
# define HEX_BASE 16

enum				e_projection
{
	ISOMETRIC,
	OBLIQUE,
	PERSPECTIVE_TOP,
	AXONOMETRIC,
	TOP
};

typedef struct s_point
{
	float			x;
	float			y;
	float			z;
	int				color;
}					t_point;

typedef struct s_rotate
{
	float			cos_ang;
	float			sin_ang;
	float			sx;
	float			sy;
	float			sz;
	float			ex;
	float			ey;
	float			ez;
}					t_rotate;

typedef struct s_flag
{
	int				help;
	int				low_color;
	int				mid_color;
	int				high_color;
}					t_flag;

typedef struct s_img
{
	void			*ptr;
	char			*data;
	int				bits_per_pixel;
	int				line_len;
	int				endian;
}					t_img;

// min_z_clr is copy of the min_z value that will be used for color calculations
// matrix_color is the matrix that will be used for restore colors
typedef struct s_map
{
	int				width;
	int				height;
	int				has_color;
	float			max_z;
	float			min_z;
	float			mid_z;
	float			min_z_clr;
	t_point			**matrix;
	int				**matrix_color;
}					t_map;

typedef struct s_cam
{
	float			scale;
	float			x_offset;
	float			y_offset;
	float			z_scale_factor;
	int				projection;
	float			rotate_x;
	float			rotate_y;
	float			rotate_z;
	int				color_mode;
	int				color_mode_activated;
	int				anti_aliasing;
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

void				copy_matrix_color(t_fdf *fdf);

// MAP | MAP UTILS
void				create_map(t_fdf *fdf);
void				scale_map(t_fdf *fdf, t_point *start_point,
						t_point *end_point);
int					get_height(char *map_name, t_fdf *fdf);
int					valid_width(int file_descriptor, int width);
void				handle_color_flag(t_fdf *fdf);
void				handle_color_for_height(t_fdf *fdf);
void				center_to_origin(t_map *map);

// EXIT
void				exit_with_error(char *error_msg, t_fdf *fdf);
void				exit_with_free(char *error_msg, t_fdf *fdf);
int					exit_mlx(void *fdf);

// UTILS
char				*itoa_with_prefix_suffix(int i, char *prefix, char *suffix);
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
void				init_matrix_color(t_fdf *fdf, t_map *map);

// FREE
void				free_all(t_fdf *fdf);
void				free_split(char **split_line);

// MATRIX
void				get_matrix(t_fdf *fdf);

// ROTATE
void				rotate_x(t_fdf *fdf, t_point *initial_p, t_point *end_p,
						float angle);
void				rotate_y(t_point *initial_p, t_point *end_p, float angle);
void				rotate_z(t_point *initial_p, t_point *end_p, float angle);

// KEYPRESS
void				handle_color(t_fdf *fdf, int key);
int					handle_keypress(int key, t_fdf *fdf);
void				set_rgb(t_fdf *fdf, int *r, int *g, int *b);

// PROJECTION
void				isometric(t_fdf *f, t_point *sp, t_point *ep);
void				oblique(t_fdf *fdf, t_point *initial_point,
						t_point *end_point);
void				perspective_top(t_fdf *fdf, t_point *start_point,
						t_point *end_point);
void				axonometric(t_point *start_point, t_point *end_point);

// CAM
void				set_z_scale_factor(t_fdf *fdf);
void				centralize(t_fdf *fdf, t_point *initial_point,
						t_point *end_point);
void				reset_cam(t_fdf *fdf);

// MENU
void				render_menu_bar(t_fdf *fdf);
void				render_menu(t_fdf *fdf);
void				show_color_mode(t_fdf *fdf);
void				show_move(t_fdf *fdf);
void				show_color(t_fdf *fdf);
void				show_location(t_fdf *fdf);
void				show_anti_aliasing(t_fdf *fdf);

// DRAW
void				draw(t_fdf *fdf, t_point start, t_point end);
void				draw_line_with_antialiasing(t_fdf *fdf, t_alg *alg);

// HELP
void				print_help(void);

#endif