/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:03:21 by johnhapke         #+#    #+#             */
/*   Updated: 2025/10/28 17:44:20 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_parse_ambient_lighting(char *line, t_rt_data *data)
{
	int	i;

	i = 0;
	data->amb_light.light_ratio = ft_prepare_to_convert_atof(line, &i, data);
	if (data->amb_light.light_ratio < 0.0 || data->amb_light.light_ratio > 1.0)
		ft_parsing_error_handler(line, "Usage: light ratio value has to be in range 0 - 1", data);
	data->amb_light.color.x = (int) ft_prepare_to_convert_atoi(line, &i, data);
	data->amb_light.color.y = (int) ft_prepare_to_convert_atoi(line, &i, data);
	data->amb_light.color.z = (int) ft_prepare_to_convert_atoi(line, &i, data);
	if (!in_range(data->amb_light.color, 0, 255))
		ft_parsing_error_handler(line, "Usage: color values have to be in range 0 - 255", data);

	printf("=== AMBIENT LIGHT DATA ===\n");
	printf("Light Ratio: %.3f\n", data->amb_light.light_ratio);
	printf("Color: RGB(%f, %f, %f) ", 
       data->amb_light.color.x, data->amb_light.color.y, data->amb_light.color.z);
	printf("(Valid: %s)\n", 
       ((data->amb_light.color.x >= 0 && data->amb_light.color.x <= 255) &&
        (data->amb_light.color.y >= 0 && data->amb_light.color.y <= 255) &&
        (data->amb_light.color.z >= 0 && data->amb_light.color.z <= 255)) ? "YES" : "NO");
	printf("===========================\n");
	data->amb_light.color = vector_divide(data->amb_light.color, 255);
}

void	ft_parse_camera(char *line, t_rt_data *data)
{
	int	i;

	i = 0;
	data->camera.viewpoint = convert_vec3(line, &i, data);
	data->camera.norm_vec = convert_vec3(line, &i, data);
	if (vector_length(data->camera.norm_vec) != 1)
		ft_parsing_error_handler(line, "Usage: vector is not normalized", data);
	data->camera.fov = (int) ft_prepare_to_convert_atoi(line, &i, data);
	if (data->camera.fov < 1 || data->camera.fov > 180)
		ft_parsing_error_handler(line, "Usage: camera fov have to be in range 1 - 180", data);

	data->camera.right = normalize(vector_cross((t_vec3){0,1,0}, data->camera.norm_vec));
	data->camera.up = normalize(vector_cross(data->camera.norm_vec, data->camera.right));
	data->camera.aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	data->camera.fov_adjust = tan(data->camera.fov * 0.5 * M_PI / 180.0);
	printf("Camera Right: (%f, %f, %f)\n", data->camera.right.x, data->camera.right.y, data->camera.right.z);
	printf("Camera Up: (%f, %f, %f)\n", data->camera.up.x, data->camera.up.y, data->camera.up.z);
	printf("Camera Forward: (%f, %f, %f)\n", data->camera.norm_vec.x, data->camera.norm_vec.y, data->camera.norm_vec.z);

	printf("=== CAMERA DATA ===\n");
	printf("Viewpoint: (%.2f, %.2f, %.2f)\n", 
       data->camera.viewpoint.x, data->camera.viewpoint.y, data->camera.viewpoint.z);
	printf("Direction: (%.2f, %.2f, %.2f)\n", 
       data->camera.norm_vec.x, data->camera.norm_vec.y, data->camera.norm_vec.z);
	printf("FOV: %.0f degrees\n", data->camera.fov);
	printf("===================\n");
}

void	ft_parse_light(char *line, t_rt_data *data)
{
	int	i;

	i = 0;
	data->light.light_point = convert_vec3(line, &i, data);
	data->light.light_ratio = ft_prepare_to_convert_atof(line, &i, data);
	if (data->light.light_ratio < 0.0 || data->light.light_ratio > 1.0)
		ft_parsing_error_handler(line, "Usage: light ratio value has to be in range 0 - 1", data);
	data->light.color.x = (int) ft_prepare_to_convert_atoi(line, &i, data);
	data->light.color.y = (int) ft_prepare_to_convert_atoi(line, &i, data);
	data->light.color.z = (int) ft_prepare_to_convert_atoi(line, &i, data);
	if (!in_range(data->light.color, 0, 255))
		ft_parsing_error_handler(line, "Usage: color values have to be in range 0 - 255", data);
	printf("=== LIGHT DATA ===\n");
	printf("Light Point: (%.2f, %.2f, %.2f)\n", 
       data->light.light_point.x, data->light.light_point.y, data->light.light_point.z);
	printf("Brightness Ratio: %.3f ", data->light.light_ratio);
	printf("(Valid: %s)\n", 
       (data->light.light_ratio >= 0.0 && data->light.light_ratio <= 1.0) ? "YES" : "NO");
	printf("Color: RGB(%f, %f, %f)\n", 
       data->light.color.x, data->light.color.y, data->light.color.z);
	printf("==================\n");
	data->light.color = vector_divide(data->light.color, 255);
}
