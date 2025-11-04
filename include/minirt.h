/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:28:02 by iherman-          #+#    #+#             */
/*   Updated: 2025/11/04 14:08:03 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"
# include <MLX42/MLX42.h>
# include <MLX42/MLX42_Int.h>

# define WINDOW_HEIGHT 1048

# define WINDOW_WIDTH 2096

# define EPSILON 1e-8

# ifndef M_PI
#  define M_PI 3.14159265359
# endif // M_PI

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_ray
{
	//t_vec3	color;
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

typedef struct s_amb_light
{
	double	light_ratio;
	t_vec3	color;
}	t_amb_light;

typedef struct s_camera
{
	t_vec3	viewpoint;
	t_vec3	norm_vec;
	t_vec3	up;
	t_vec3	right;
	double	aspect_ratio;
	double	fov_adjust;
	double	fov;
}	t_camera;

typedef struct s_light
{
	t_vec3	light_point;
	double	light_ratio;
	t_vec3	color;
}	t_light;

typedef struct s_sphere
{
	t_vec3	pos;
	double	diameter;
	t_vec3	color;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	pos;
	t_vec3	norm_vec;
	t_vec3	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	pos;
	t_vec3	norm_vec;
	double	diameter;
	double	height;
	t_vec3	color;
}	t_cylinder;

typedef struct s_hitinfo
{
	double		t;
	t_vec3		surface_dir;
	t_vec3		pos;
	t_vec3		obj_color;
}	t_hitinfo;

typedef struct s_obj
{
	void			*obj;
	int				(*check_intersection)(void *obj, t_ray ray, t_hitinfo *hit);
	struct s_obj	*next;
}	t_obj;

typedef struct s_rt_data
{
	mlx_t		*mlx_win;
	mlx_image_t	*mlx_img;
	t_amb_light	amb_light;
	t_camera	camera;
	t_light		light;
	t_obj		*obj;
	bool		error;
}	t_rt_data;

// parser
void			parsing_handler(char *file, t_rt_data *data);
void			parsing_error_handler(char *line, char *msg, t_rt_data *data);
void			free_parsing(char *line, t_rt_data *data);
void			parse_ambient_lighting(char *line, t_rt_data *data);
void			parse_camera(char *line, t_rt_data *data);
void			parse_light(char *line, t_rt_data *data);
void			parse_sphere(char *line, t_rt_data *data);
void			parse_plane(char *line, t_rt_data *data);
void			parse_cylinder(char *line, t_rt_data *data);
void			control_type_identifier(char *file, t_rt_data *data);
double			prepare_to_convert_atoi(char *line, int *i, t_rt_data *data);
double			prepare_to_convert_atof(char *line, int *i, t_rt_data *data);
int				sphere_addback(t_obj **obj, t_sphere *node);
int				plane_addback(t_obj **obj, t_plane *node);
int				cylinder_addback(t_obj **obj, t_cylinder *node);
bool			match_format(const char *restrict format, const char *line);

void			mlx_handler(t_rt_data *data);
void			move_camera(mlx_key_data_t keydata, t_camera *camera);

t_vec3			convert_vec3(char *line, int *i, t_rt_data *data);
bool			in_range(t_vec3 vec, double rl, double ru);
bool			is_normalized(t_vec3 vec);

// vector math
t_vec3			normalize(t_vec3 vec);
double			vector_length_squared(t_vec3 vec);
double			vector_length(t_vec3 vec);
t_vec3			vector_add(t_vec3 vec1, t_vec3 vec2);
t_vec3			vector_subtract(t_vec3 vec1, t_vec3 vec2);
t_vec3			vector_multiply(t_vec3 vec, const double factor);
t_vec3			vector_divide(t_vec3 vec, const double factor);
bool			vector_is_larger(t_vec3 larger, t_vec3 smaller);
t_vec3			vector_cross(t_vec3 vec1, t_vec3 vec2);
double			vector_dot(t_vec3 vec1, t_vec3 vec2);

// engine
void			raytracer(void *tmp_data);
unsigned int	shoot_ray(t_rt_data *data, int screen_x, int screen_y);
t_ray			generate_ray(t_rt_data *data, int screenX, int screenY);

// intersection
int				intersect_sphere(void *obj, t_ray ray, t_hitinfo *hit);
int				intersect_cylinder(void *obj, t_ray ray, t_hitinfo *hit);
int				intersect_plane(void *obj, t_ray ray, t_hitinfo *hit);
double			determine_t(double a, double b, double discriminant);

unsigned int	calculate_color(const t_hitinfo *hitinfo, t_rt_data *data);

#endif // MINIRT_H
