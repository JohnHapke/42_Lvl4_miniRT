/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:28:02 by iherman-          #+#    #+#             */
/*   Updated: 2025/10/02 13:12:31 by iherman-         ###   ########.fr       */
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

# define WINDOW_HEIGHT 600//1048

#  define WINDOW_WIDTH 800//2096

// very small number to add tolerance for floating point comparisons
# define EPSILON 1e-8

/*
	To get normalized vector (for direction)
		Get the magnitude: √(x² + y² + z²) = magnitude
		Divide all components by magnitude: x/magnitude, y/magnitude, z/magnitude
	Mostly useful for getting a clean direction for our vec3
*/

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;


typedef struct s_color
{
	double		R;
	double		G;
	double		B;
}	t_color;

typedef struct s_ray
{
	//t_color	color;
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

typedef	struct s_amb_light
{
	double	light_ratio;
	t_color	color;
}	t_amb_light;

typedef struct s_camera
{
	t_vec3	viewpoint;
	t_vec3	norm_vec;
	t_vec3	up;
	t_vec3	right;
	double	fov;
}	t_camera;

typedef	struct s_light
{
	t_vec3	light_point;
	double	bright_ratio;
	t_color	color;
}	t_light;
typedef struct s_sphere
{
	t_vec3	pos;
	double	diameter;
	t_color	color;
}	t_sphere;

typedef	struct s_plane
{
	t_vec3	pos;
	t_vec3	norm_vec;
	t_color	color;
}	t_plane;

typedef	struct s_cylinder
{
	t_vec3	pos;
	t_vec3	norm_vec;
	double	diameter;
	double	height;
	t_color	color;
}	t_cylinder;

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_obj_type;

typedef struct s_hitinfo
{
	double		t;
	t_vec3		surface_dir;
	t_vec3		pos;
	t_color		obj_color;

	void		*obj; // may not be neccessary
	t_obj_type	obj_type;
}	t_hitinfo;
typedef struct s_obj
{
	void			*obj;
	t_obj_type		type;
	int				(*fct_ptr)(void *obj, t_ray ray, t_hitinfo *hit);
	struct s_obj	*next;
}	t_obj;

typedef struct s_rt_data
{
	mlx_t		*mlx_win;
	mlx_image_t		*mlx_img;
	t_amb_light	amb_light;
	t_camera	camera;
	t_light		light;
	t_obj		*obj;
}	t_rt_data;

// parser
void	ft_parsing_handler(char *file, t_rt_data *data);
void	ft_parsing_error_handler(char *line, t_rt_data *data);
void	ft_free_parsing(char *line, t_rt_data *data);
void	ft_parse_ambient_lighting(char *line, t_rt_data *data);
void	ft_parse_camera(char *line, t_rt_data *data);
void	ft_parse_light(char *line, t_rt_data *data);
void	ft_parse_sphere(char *line, t_rt_data *data);
void	ft_parse_plane(char *line, t_rt_data *data);
void	ft_parse_cylinder(char *line, t_rt_data *data);
void 	ft_control_type_identifier(char *file, t_rt_data *data);
double	ft_prepare_to_convert_atoi(const char *line, int *i, t_rt_data *data);
double	ft_prepare_to_convert_atof(const char *line, int *i, t_rt_data *data);
// void	ft_control_line_end(char *line, int *i, t_rt_data *data);
int		sphere_addback(t_obj **obj, t_sphere *node);
int		plane_addback(t_obj **obj, t_plane *node);
int		cylinder_addback(t_obj **obj, t_cylinder *node);

// vector math
t_vec3	normalize(t_vec3 vec);
double	vector_length_squared(t_vec3 vec);
double	vector_length(t_vec3 vec);
t_vec3	vector_add(t_vec3 vec1, t_vec3 vec2);
t_vec3	vector_subtract(t_vec3 vec1, t_vec3 vec2);
t_vec3	vector_multiply(t_vec3 vec, const double factor);
t_vec3	vector_divide(t_vec3 vec, const double factor);
bool	vector_is_larger(t_vec3 larger, t_vec3 smaller);
t_vec3	vector_cross(t_vec3 vec1, t_vec3 vec2);
double	vector_dot(t_vec3 vec1, t_vec3 vec2);

// engine
void	raytracer(void *tmp_data);
unsigned int	shoot_ray(t_rt_data *data, int screen_x, int screen_y);
t_ray	generate_ray(t_rt_data *data, int screenX, int screenY);

// sphere
int				intersect_sphere(void *obj, t_ray ray, t_hitinfo *hit);
int				intersect_cylinder(void *obj, t_ray ray, t_hitinfo *hit);
int				intersect_plane(void *obj, t_ray ray, t_hitinfo *hit);

unsigned int	calculate_color(const t_hitinfo *hitinfo, t_rt_data * data);

#endif // MINIRT_H
