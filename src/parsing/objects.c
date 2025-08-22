/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:48:11 by johnhapke         #+#    #+#             */
/*   Updated: 2025/08/22 14:54:01 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_parse_sphere(char *line, t_rt_data *data)
{
	int	i;

	i = 0;
	data->sphere = malloc(sizeof(t_sphere));
	if (!data->sphere)
		ft_parsing_error_handler(NULL);
	data->sphere->pos.x = ft_export_and_convert_atof(line, &i);
	data->sphere->pos.y = ft_export_and_convert_atof(line, &i);
	data->sphere->pos.z = ft_export_and_convert_atof(line, &i);
	data->sphere->diameter = ft_export_and_convert_atof(line, &i);
	if (data->sphere->diameter <= 0.0)
		ft_parsing_error_handler(data);
	data->sphere->color.R = ft_export_and_convert_atoi(line, &i);
	data->sphere->color.G = ft_export_and_convert_atoi(line, &i);
	data->sphere->color.B = ft_export_and_convert_atoi(line, &i);
	if ((data->sphere->color.R < 0 || data->sphere->color.R > 255) || (data->sphere->color.G < 0
		|| data->sphere->color.G > 255) || (data->sphere->color.B < 0 || data->sphere->color.B > 255))
		ft_parsing_error_handler(data);
	printf("=== SPHERE DATA ===\n");
printf("Position: (%.2f, %.2f, %.2f)\n", 
       data->sphere->pos.x, data->sphere->pos.y, data->sphere->pos.z);
printf("Diameter: %.2f\n", data->sphere->diameter);
printf("Color: RGB(%d, %d, %d) ", 
       data->sphere->color.R, data->sphere->color.G, data->sphere->color.B);
printf("(Valid: %s)\n", 
       ((data->sphere->color.R >= 0 && data->sphere->color.R <= 255) &&
        (data->sphere->color.G >= 0 && data->sphere->color.G <= 255) &&
        (data->sphere->color.B >= 0 && data->sphere->color.B <= 255)) ? "YES" : "NO");
printf("===================\n");
}

void	ft_parse_plane(char *line, t_rt_data *data)
{
	int	i;

	i = 0;
	data->plane = malloc(sizeof(t_plane));
	if (!data->plane)
		ft_parsing_error_handler(data);
	data->plane->pos.x = ft_export_and_convert_atof(line, &i);
	data->plane->pos.y = ft_export_and_convert_atof(line, &i);
	data->plane->pos.z = ft_export_and_convert_atof(line, &i);
	data->plane->norm_vec.x = ft_export_and_convert_atof(line, &i);
	data->plane->norm_vec.y = ft_export_and_convert_atof(line, &i);
	data->plane->norm_vec.z = ft_export_and_convert_atof(line, &i);
	if ((data->plane->norm_vec.x < 0 || data->plane->norm_vec.x > 1) || (data->plane->norm_vec.y < 0
		|| data->plane->norm_vec.y > 1) || (data->plane->norm_vec.z < 0 || data->plane->norm_vec.z > 1))
		ft_parsing_error_handler(data);
	data->plane->color.R = ft_export_and_convert_atoi(line, &i);
	data->plane->color.G = ft_export_and_convert_atoi(line, &i);
	data->plane->color.B = ft_export_and_convert_atoi(line, &i);
	if ((data->plane->color.R < 0 || data->plane->color.R > 255) || (data->plane->color.G < 0
		|| data->plane->color.G > 255) || (data->plane->color.B < 0 || data->plane->color.B > 255))
		ft_parsing_error_handler(data);
	printf("=== PLANE DATA ===\n");
printf("Position: (%.2f, %.2f, %.2f)\n", 
       data->plane->pos.x, data->plane->pos.y, data->plane->pos.z);
printf("Normal Vector: (%.2f, %.2f, %.2f)\n", 
       data->plane->norm_vec.x, data->plane->norm_vec.y, data->plane->norm_vec.z);
printf("Color: RGB(%d, %d, %d)\n", 
       data->plane->color.R, data->plane->color.G, data->plane->color.B);
printf("==================\n");
}

void	ft_parse_cylinder(char *line, t_rt_data *data)
{
	int	i;

	i = 0;
	data->cylinder = malloc(sizeof(t_cylinder));
	if (!data->cylinder)
		ft_parsing_error_handler(data);
	data->cylinder->pos.x = ft_export_and_convert_atof(line, &i);
	data->cylinder->pos.y = ft_export_and_convert_atof(line, &i);
	data->cylinder->pos.z = ft_export_and_convert_atof(line, &i);
	data->cylinder->norm_vec.x = ft_export_and_convert_atof(line, &i);
	data->cylinder->norm_vec.y = ft_export_and_convert_atof(line, &i);
	data->cylinder->norm_vec.z = ft_export_and_convert_atof(line, &i);
	if ((data->cylinder->norm_vec.x < 0 || data->cylinder->norm_vec.x > 1) || (data->cylinder->norm_vec.y < 0
		|| data->cylinder->norm_vec.y > 1) || (data->cylinder->norm_vec.z < 0 || data->cylinder->norm_vec.z > 1))
		ft_parsing_error_handler(data);
	data->cylinder->diameter = ft_export_and_convert_atof(line, &i);
	if (data->cylinder->diameter <= 0.0)
		ft_parsing_error_handler(data);
	data->cylinder->height = ft_export_and_convert_atof(line, &i);
	if (data->cylinder->height <= 0.0)
		ft_parsing_error_handler(data);
	data->cylinder->color.R = ft_export_and_convert_atoi(line, &i);
	data->cylinder->color.G = ft_export_and_convert_atoi(line, &i);
	data->cylinder->color.B = ft_export_and_convert_atoi(line, &i);
	if ((data->cylinder->color.R < 0 || data->cylinder->color.R > 255) || (data->cylinder->color.G < 0
		|| data->cylinder->color.G > 255) || (data->cylinder->color.B < 0 || data->cylinder->color.B > 255))
		ft_parsing_error_handler(data);
	printf("=== CYLINDER DATA ===\n");
printf("Position: (%.2f, %.2f, %.2f)\n", 
       data->cylinder->pos.x, data->cylinder->pos.y, data->cylinder->pos.z);
printf("Normal Vector: (%.2f, %.2f, %.2f) ", 
       data->cylinder->norm_vec.x, data->cylinder->norm_vec.y, data->cylinder->norm_vec.z);
printf("(Valid: %s)\n", 
       ((data->cylinder->norm_vec.x >= 0 && data->cylinder->norm_vec.x <= 1) &&
        (data->cylinder->norm_vec.y >= 0 && data->cylinder->norm_vec.y <= 1) &&
        (data->cylinder->norm_vec.z >= 0 && data->cylinder->norm_vec.z <= 1)) ? "YES" : "NO");
printf("Diameter: %.2f\n", data->cylinder->diameter);
printf("Height: %.2f\n", data->cylinder->height);
printf("Color: RGB(%d, %d, %d) ", 
       data->cylinder->color.R, data->cylinder->color.G, data->cylinder->color.B);
printf("(Valid: %s)\n", 
       ((data->cylinder->color.R >= 0 && data->cylinder->color.R <= 255) &&
        (data->cylinder->color.G >= 0 && data->cylinder->color.G <= 255) &&
        (data->cylinder->color.B >= 0 && data->cylinder->color.B <= 255)) ? "YES" : "NO");
printf("=====================\n");
}
