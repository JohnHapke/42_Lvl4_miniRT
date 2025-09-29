/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:03:21 by johnhapke         #+#    #+#             */
/*   Updated: 2025/09/29 15:26:55 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_parse_ambient_lighting(char *line, t_rt_data *data)
{
	int	i;

	i = 0;
	data->amb_light.light_ratio = ft_prepare_to_convert_atof(line, &i, data);
	if (data->amb_light.light_ratio < 0.0 || data->amb_light.light_ratio > 1.0)
		ft_parsing_error_handler(line, data);
	data->amb_light.color.R = (int) ft_prepare_to_convert_atoi(line, &i, data);
	data->amb_light.color.G = (int) ft_prepare_to_convert_atoi(line, &i, data);
	data->amb_light.color.B = (int) ft_prepare_to_convert_atoi(line, &i, data);
	if ((data->amb_light.color.R < 0 || data->amb_light.color.R > 255) || (data->amb_light.color.G < 0
		|| data->amb_light.color.G > 255) || (data->amb_light.color.B < 0 || data->amb_light.color.B > 255))
		ft_parsing_error_handler(line, data);
	if (line[i] != '\n' && line[i] != '\0')
		ft_parsing_error_handler(line, data);

	printf("=== AMBIENT LIGHT DATA ===\n");
	printf("Light Ratio: %.3f\n", data->amb_light.light_ratio);
	printf("Color: RGB(%f, %f, %f) ", 
       data->amb_light.color.R, data->amb_light.color.G, data->amb_light.color.B);
	printf("(Valid: %s)\n", 
       ((data->amb_light.color.R >= 0 && data->amb_light.color.R <= 255) &&
        (data->amb_light.color.G >= 0 && data->amb_light.color.G <= 255) &&
        (data->amb_light.color.B >= 0 && data->amb_light.color.B <= 255)) ? "YES" : "NO");
	printf("===========================\n");
}

void	ft_parse_camera(char *line, t_rt_data *data)
{
	int	i;

	i = 0;
	data->camera.viewpoint.x = ft_prepare_to_convert_atof(line, &i, data);
	data->camera.viewpoint.y = ft_prepare_to_convert_atof(line, &i, data);
	data->camera.viewpoint.z = ft_prepare_to_convert_atof(line, &i, data);
	data->camera.norm_vec.x = ft_prepare_to_convert_atof(line, &i, data);
	data->camera.norm_vec.y = ft_prepare_to_convert_atof(line, &i, data);
	data->camera.norm_vec.z = ft_prepare_to_convert_atof(line, &i, data);
	if ((data->camera.norm_vec.x < -1 || data->camera.norm_vec.x > 1) || (data->camera.norm_vec.y < -1
		|| data->camera.norm_vec.y > 1) || (data->camera.norm_vec.z < -1 || data->camera.norm_vec.z > 1))
		ft_parsing_error_handler(line, data);
	data->camera.fov = (int) ft_prepare_to_convert_atoi(line, &i, data);
	if (data->camera.fov < 0 || data->camera.fov > 180)
		ft_parsing_error_handler(line, data);
	if (line[i] != '\n' && line[i] != '\0')
		ft_parsing_error_handler(line, data);
	//data->camera.norm_vec = normalize(data->camera.norm_vec);
	data->camera.right = normalize(vector_cross((t_vec3){0,1,0}, data->camera.norm_vec));
	data->camera.up = normalize(vector_cross(data->camera.norm_vec, data->camera.right));
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
	data->light.light_point.x = ft_prepare_to_convert_atof(line, &i, data);
	data->light.light_point.y = ft_prepare_to_convert_atof(line, &i, data);
	data->light.light_point.z = ft_prepare_to_convert_atof(line, &i, data);
	data->light.bright_ratio = ft_prepare_to_convert_atof(line, &i, data);
	if (data->light.bright_ratio < 0.0 || data->light.bright_ratio > 1.0)
		ft_parsing_error_handler(line, data);
	data->light.color.R = (int) ft_prepare_to_convert_atoi(line, &i, data);
	data->light.color.G = (int) ft_prepare_to_convert_atoi(line, &i, data);
	data->light.color.B = (int) ft_prepare_to_convert_atoi(line, &i, data);
	if ((data->light.color.R < 0 || data->light.color.R > 255) || (data->light.color.G < 0
		|| data->light.color.G > 255) || (data->light.color.B < 0 || data->light.color.B > 255))
		ft_parsing_error_handler(line, data);
	if (line[i] != '\n' && line[i] != '\0')
		ft_parsing_error_handler(line, data);

	printf("=== LIGHT DATA ===\n");
	printf("Light Point: (%.2f, %.2f, %.2f)\n", 
       data->light.light_point.x, data->light.light_point.y, data->light.light_point.z);
	printf("Brightness Ratio: %.3f ", data->light.bright_ratio);
	printf("(Valid: %s)\n", 
       (data->light.bright_ratio >= 0.0 && data->light.bright_ratio <= 1.0) ? "YES" : "NO");
	printf("Color: RGB(%f, %f, %f)\n", 
       data->light.color.R, data->light.color.G, data->light.color.B);
	printf("==================\n");
}
