/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:48:11 by johnhapke         #+#    #+#             */
/*   Updated: 2025/11/10 11:57:13 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(char *line, t_rt_data *data)
{
	int			i;
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		parsing_error_handler(line, "Internal: malloc failure", data);
	i = 0;
	sphere->pos = convert_vec3(line, &i, data);
	sphere->diameter = prepare_to_convert_atof(line, &i, data);
	sphere->color.x = (int) prepare_to_convert_atoi(line, &i, data);
	sphere->color.y = (int) prepare_to_convert_atoi(line, &i, data);
	sphere->color.z = (int) prepare_to_convert_atoi(line, &i, data);
	if (sphere_addback(&(data->obj), sphere) == 1)
	{
		free(sphere);
		parsing_error_handler(line, "Internal: malloc falure", data);
	}
	if (sphere->diameter <= EPSILON)
		parsing_error_handler(line,
			"Usage: sphere diameter cannot be < EPSILON", data);
	if (!in_range(sphere->color, 0, 255))
		parsing_error_handler(line,
			"Usage: color values have to be in range 0 - 255", data);
	sphere->color = vector_divide(sphere->color, 255);
}

void	parse_plane(char *line, t_rt_data *data)
{
	int		i;
	t_plane	*plane;

	i = 0;
	plane = malloc(sizeof(t_plane));
	if (!plane)
		parsing_error_handler(line, "Internal: malloc failure", data);
	plane->pos = convert_vec3(line, &i, data);
	plane->norm_vec = convert_vec3(line, &i, data);
	plane->norm_vec = normalize(plane->norm_vec);
	plane->color.x = (int) prepare_to_convert_atoi(line, &i, data);
	plane->color.y = (int) prepare_to_convert_atoi(line, &i, data);
	plane->color.z = (int) prepare_to_convert_atoi(line, &i, data);
	if (plane_addback(&(data->obj), plane) == 1)
	{
		free(plane);
		parsing_error_handler(line, "Internal: malloc failure", data);
	}
	if (!is_normalized(plane->norm_vec))
		parsing_error_handler(line, "Usage: vector is not normalized", data);
	if (!in_range(plane->color, 0, 255))
		parsing_error_handler(line,
			"Usage: color values have to be in range 0 - 255", data);
	plane->color = vector_divide(plane->color, 255);
}

static void	control_error_cyl(char *line, t_cylinder *cylinder, t_rt_data *data)
{
	if (cylinder_addback(&data->obj, cylinder) == 1)
	{
		free(cylinder);
		parsing_error_handler(line, "Internal: malloc failure", data);
	}
	if (!is_normalized(cylinder->norm_vec))
		parsing_error_handler(line, "Usage: vector is not normalized", data);
	cylinder->norm_vec = normalize(cylinder->norm_vec);
	if (cylinder->diameter <= EPSILON)
		parsing_error_handler(line,
			"Usage: cylinder diameter cannot be < EPSILON", data);
	if (cylinder->height <= EPSILON)
		parsing_error_handler(line,
			"Usage: cylinder height cannot be < EPSILON", data);
	if (!in_range(cylinder->color, 0, 255))
		parsing_error_handler(line,
			"Usage: color values have to be in range 0 - 255", data);
	cylinder->color = vector_divide(cylinder->color, 255);
}

void	parse_cylinder(char *line, t_rt_data *data)
{
	int			i;
	t_cylinder	*cylinder;

	i = 0;
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		parsing_error_handler(line, "Internal: malloc failure", data);
	cylinder->pos = convert_vec3(line, &i, data);
	cylinder->norm_vec = convert_vec3(line, &i, data);
	cylinder->diameter = prepare_to_convert_atof(line, &i, data);
	cylinder->height = prepare_to_convert_atof(line, &i, data);
	cylinder->color.x = (int) prepare_to_convert_atoi(line, &i, data);
	cylinder->color.y = (int) prepare_to_convert_atoi(line, &i, data);
	cylinder->color.z = (int) prepare_to_convert_atoi(line, &i, data);
	control_error_cyl(line, cylinder, data);
}
