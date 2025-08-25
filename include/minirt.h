/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:28:02 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/25 19:08:30 by iherman-         ###   ########.fr       */
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

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 528
# endif // WINDOW_HEIGHT

# ifndef WINDOWN_WIDTH
#  define WINDOW_WIDTH 1048
# endif // WINDOW_WIDTH

# define MAX_BOUNCE 5

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

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

typedef struct s_color
{
	int		R;
	int		G;
	int		B;
}	t_color;

typedef	struct s_amb_light
{
	double	light_ratio;
	t_color	color;
}	t_amb_light;

typedef struct s_camera
{
	t_vec3	viewpoint;
	t_vec3	norm_vec;
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

typedef struct s_rt_data
{
	t_amb_light	amb_light;
	t_camera	camera;
	t_light		light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
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

#endif // MINIRT_H
