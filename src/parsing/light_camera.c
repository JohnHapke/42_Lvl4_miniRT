/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:03:21 by johnhapke         #+#    #+#             */
/*   Updated: 2025/11/04 13:21:06 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_ambient_lighting(char *line, t_rt_data *data)
{
	int	i;

	i = 0;
	data->amb_light.light_ratio = prepare_to_convert_atof(line, &i, data);
	if (data->amb_light.light_ratio < 0.0 || data->amb_light.light_ratio > 1.0)
		parsing_error_handler(line,
			"Usage: light ratio value has to be in range 0 - 1", data);
	data->amb_light.color.x = (int) prepare_to_convert_atoi(line, &i, data);
	data->amb_light.color.y = (int) prepare_to_convert_atoi(line, &i, data);
	data->amb_light.color.z = (int) prepare_to_convert_atoi(line, &i, data);
	if (!in_range(data->amb_light.color, 0, 255))
		parsing_error_handler(line,
			"Usage: color values have to be in range 0 - 255", data);
	data->amb_light.color = vector_divide(data->amb_light.color, 255);
}

void	parse_camera(char *line, t_rt_data *data)
{
	int	i;

	i = 0;
	data->camera.viewpoint = convert_vec3(line, &i, data);
	data->camera.norm_vec = convert_vec3(line, &i, data);
	if (vector_length(data->camera.norm_vec) != 1)
		parsing_error_handler(line, "Usage: vector is not normalized", data);
	data->camera.fov = (int) prepare_to_convert_atoi(line, &i, data);
	if (data->camera.fov < 1 || data->camera.fov > 180)
		parsing_error_handler(line,
			"Usage: camera fov have to be in range 1 - 180", data);
	data->camera.right = normalize(vector_cross((t_vec3){0, 1, 0},
				data->camera.norm_vec));
	data->camera.up = normalize(vector_cross(data->camera.norm_vec,
				data->camera.right));
	data->camera.aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	data->camera.fov_adjust = tan(data->camera.fov * 0.5 * M_PI / 180.0);
}

void	parse_light(char *line, t_rt_data *data)
{
	int	i;

	i = 0;
	data->light.light_point = convert_vec3(line, &i, data);
	data->light.light_ratio = prepare_to_convert_atof(line, &i, data);
	if (data->light.light_ratio < 0.0 || data->light.light_ratio > 1.0)
		parsing_error_handler(line,
			"Usage: light ratio value has to be in range 0 - 1", data);
	data->light.color.x = (int) prepare_to_convert_atoi(line, &i, data);
	data->light.color.y = (int) prepare_to_convert_atoi(line, &i, data);
	data->light.color.z = (int) prepare_to_convert_atoi(line, &i, data);
	if (!in_range(data->light.color, 0, 255))
		parsing_error_handler(line,
			"Usage: color values have to be in range 0 - 255", data);
	data->light.color = vector_divide(data->light.color, 255);
}
