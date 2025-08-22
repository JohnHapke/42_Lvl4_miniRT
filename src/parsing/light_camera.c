/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:03:21 by johnhapke         #+#    #+#             */
/*   Updated: 2025/08/22 15:02:05 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_parse_ambient_lighting(char *line, t_rt_data *data)
{
	int	i;

	i = 0;
	data->amb_light.light_ratio = ft_export_and_convert_atof(line, &i);
	if (data->amb_light.light_ratio < 0.0 || data->amb_light.light_ratio > 1.0)
		ft_parsing_error_handler(NULL);
	data->amb_light.color.R = ft_export_and_convert_atoi(line, &i);
	data->amb_light.color.G = ft_export_and_convert_atoi(line, &i);
	data->amb_light.color.B = ft_export_and_convert_atoi(line, &i);
	if ((data->amb_light.color.R < 0 || data->amb_light.color.R > 255) || (data->amb_light.color.G < 0
		|| data->amb_light.color.G > 255) || (data->amb_light.color.B < 0 || data->amb_light.color.B > 255))
		ft_parsing_error_handler(NULL);
	printf("=== AMBIENT LIGHT DATA ===\n");
printf("Light Ratio: %.3f\n", data->amb_light.light_ratio);
printf("Color: RGB(%d, %d, %d) ", 
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
	data->camera.viewpoint.x = ft_export_and_convert_atof(line, &i);
	data->camera.viewpoint.y = ft_export_and_convert_atof(line, &i);
	data->camera.viewpoint.z = ft_export_and_convert_atof(line, &i);
	data->camera.norm_vec.x = ft_export_and_convert_atof(line, &i);
	data->camera.norm_vec.y = ft_export_and_convert_atof(line, &i);
	data->camera.norm_vec.z = ft_export_and_convert_atof(line, &i);
	if ((data->camera.norm_vec.x < 0 || data->camera.norm_vec.x > 1) || (data->camera.norm_vec.y < 0
		|| data->camera.norm_vec.y > 1) || (data->camera.norm_vec.z < 0 || data->camera.norm_vec.z > 1))
		ft_parsing_error_handler(NULL);
	data->camera.fov = ft_export_and_convert_atoi(line, &i);
	if (data->camera.fov < 0 || data->camera.fov > 180)
		ft_parsing_error_handler(NULL);
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
	data->light.light_point.x = ft_export_and_convert_atof(line, &i);
	data->light.light_point.y = ft_export_and_convert_atof(line, &i);
	data->light.light_point.z = ft_export_and_convert_atof(line, &i);
	data->light.bright_ratio = ft_export_and_convert_atof(line, &i);
	if (data->light.bright_ratio < 0.0 || data->light.bright_ratio > 1.0)
		ft_parsing_error_handler(NULL);
	data->light.color.R = ft_export_and_convert_atoi(line, &i);
	data->light.color.G = ft_export_and_convert_atoi(line, &i);
	data->light.color.B = ft_export_and_convert_atoi(line, &i);
	if ((data->light.color.R < 0 || data->light.color.R > 255) || (data->light.color.G < 0
		|| data->light.color.G > 255) || (data->light.color.B < 0 || data->light.color.B > 255))
		ft_parsing_error_handler(NULL);
	printf("=== LIGHT DATA ===\n");
printf("Light Point: (%.2f, %.2f, %.2f)\n", 
       data->light.light_point.x, data->light.light_point.y, data->light.light_point.z);
printf("Brightness Ratio: %.3f ", data->light.bright_ratio);
printf("(Valid: %s)\n", 
       (data->light.bright_ratio >= 0.0 && data->light.bright_ratio <= 1.0) ? "YES" : "NO");
printf("Color: RGB(%d, %d, %d)\n", 
       data->light.color.R, data->light.color.G, data->light.color.B);
printf("==================\n");
}
