/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:03:21 by johnhapke         #+#    #+#             */
/*   Updated: 2025/08/21 15:35:36 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_parse_ambient_lighting(char *line, t_rt_data *data)
{
	printf("ambient light\n");
	int	i;

	i = 0;
	data->amb_light.light_ratio = ft_export_and_convert_atof(line, &i);
	data->amb_light.R = ft_export_and_convert_atoi(line, &i);
	data->amb_light.G = ft_export_and_convert_atoi(line, &i);
	data->amb_light.B = ft_export_and_convert_atoi(line, &i);
	if ((data->amb_light.R < 0 || data->amb_light.R > 255) || (data->amb_light.G < 0
		|| data->amb_light.G > 180) || (data->amb_light.B < 0 || data->amb_light.B > 180))
	
	printf("ratio: %f, R: %i, G: %i, B: %i \n", data->amb_light.light_ratio, data->amb_light.R, data->amb_light.G, data->amb_light.B);
}

void	ft_parse_camera(char *line, t_rt_data *data)
{
	printf("camera\n");
	int	i;

	i = 0;
	data->camera.viewpoint.x = ft_export_and_convert_atof(line, &i);
	printf("cam.view.x: %f \n", data->camera.viewpoint.x);
	data->camera.viewpoint.y = ft_export_and_convert_atof(line, &i);
	data->camera.viewpoint.z = ft_export_and_convert_atof(line, &i);
	data->camera.direction.x = ft_export_and_convert_atof(line, &i);
	data->camera.direction.y = ft_export_and_convert_atof(line, &i);
	data->camera.direction.z = ft_export_and_convert_atof(line, &i);
	data->camera.fov = ft_export_and_convert_atoi(line, &i);
	if (data->camera.fov < 0 || data->camera.fov > 180)
		ft_parsing_error_handler();
	printf("cam.view.x: %f, cam.view.y: %f, cam.view.z: %f \n", data->camera.viewpoint.x, data->camera.viewpoint.y, data->camera.viewpoint.z);
}

void	ft_parse_light(char *line, t_rt_data *data)
{
	printf("light\n");
	int	i;

	i = 0;
	data->light.light_point.x = ft_export_and_convert_atof(line, &i);
	data->light.light_point.y = ft_export_and_convert_atof(line, &i);
	data->light.light_point.z = ft_export_and_convert_atof(line, &i);
	printf("LIGHT x=%f , y=%f , z=%f \n", data->light.light_point.x, data->light.light_point.y, data->light.light_point.z);
	data->light.bright_ratio = ft_export_and_convert_atof(line, &i);
	if (data->light.bright_ratio < 0.0 || data->light.bright_ratio > 1.0)
		ft_parsing_error_handler();
	printf("LIGHT ratio=%f \n", data->light.bright_ratio);
	data->light.R = ft_export_and_convert_atoi(line, &i);
	data->light.G = ft_export_and_convert_atoi(line, &i);
	data->light.B = ft_export_and_convert_atoi(line, &i);
	if ((data->light.R < 0 || data->light.R > 255) || (data->light.G < 0
		|| data->light.G > 255) || (data->light.B < 0 || data->light.B > 255))
		ft_parsing_error_handler();
	
}
