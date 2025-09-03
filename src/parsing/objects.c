/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:48:11 by johnhapke         #+#    #+#             */
/*   Updated: 2025/09/03 12:35:13 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_parse_sphere(char *line, t_rt_data *data)
{
	int	i;
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		ft_parsing_error_handler(line, data);
	i = 0;
	sphere->pos.x = ft_prepare_to_convert_atof(line, &i, data);
	sphere->pos.y = ft_prepare_to_convert_atof(line, &i, data);
	sphere->pos.z = ft_prepare_to_convert_atof(line, &i, data);
	sphere->diameter = ft_prepare_to_convert_atof(line, &i, data);
	if (sphere->diameter <= 0.0)
		ft_parsing_error_handler(line, data);
	sphere->color.R = (int) ft_prepare_to_convert_atoi(line, &i, data);
	sphere->color.G = (int) ft_prepare_to_convert_atoi(line, &i, data);
	sphere->color.B = (int) ft_prepare_to_convert_atoi(line, &i, data);
	if ((sphere->color.R < 0 || sphere->color.R > 255) || (sphere->color.G < 0
		|| sphere->color.G > 255) || (sphere->color.B < 0 || sphere->color.B > 255))
		ft_parsing_error_handler(line, data);
	if (line[i] != '\n' && line[i] != '\0')
		ft_parsing_error_handler(line, data);
	if (sphere_addback(&(data->obj), sphere) == 1)
		ft_parsing_error_handler(line, data);
}

void	ft_parse_plane(char *line, t_rt_data *data)
{
	int	i;
	t_plane	*plane;

	i = 0;
	plane = malloc(sizeof(t_plane));
	if (!plane)
		ft_parsing_error_handler(line, data);
	plane->pos.x = ft_prepare_to_convert_atof(line, &i, data);
	plane->pos.y = ft_prepare_to_convert_atof(line, &i, data);
	plane->pos.z = ft_prepare_to_convert_atof(line, &i, data);
	plane->norm_vec.x = ft_prepare_to_convert_atof(line, &i, data);
	plane->norm_vec.y = ft_prepare_to_convert_atof(line, &i, data);
	plane->norm_vec.z = ft_prepare_to_convert_atof(line, &i, data);
	if ((plane->norm_vec.x < -1 || plane->norm_vec.x > 1) || (plane->norm_vec.y < -1
		|| plane->norm_vec.y > 1) || (plane->norm_vec.z < -1 || plane->norm_vec.z > 1))
		ft_parsing_error_handler(line, data);
	plane->color.R = (int) ft_prepare_to_convert_atoi(line, &i, data);
	plane->color.G = (int) ft_prepare_to_convert_atoi(line, &i, data);
	plane->color.B = (int) ft_prepare_to_convert_atoi(line, &i, data);
	if ((plane->color.R < 0 || plane->color.R > 255) || (plane->color.G < 0
		|| plane->color.G > 255) || (plane->color.B < 0 || plane->color.B > 255))
		ft_parsing_error_handler(line, data);
	if (line[i] != '\n' && line[i] != '\0')
		ft_parsing_error_handler(line, data);
	if (plane_addback(&(data->obj), plane) == 1)
		ft_parsing_error_handler(line, data);
}

void	ft_parse_cylinder(char *line, t_rt_data *data)
{
	int	i;
	t_cylinder	*cylinder;

	i = 0;
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		ft_parsing_error_handler(line, data);
	cylinder->pos.x = ft_prepare_to_convert_atof(line, &i, data);
	cylinder->pos.y = ft_prepare_to_convert_atof(line, &i, data);
	cylinder->pos.z = ft_prepare_to_convert_atof(line, &i, data);
	cylinder->norm_vec.x = ft_prepare_to_convert_atof(line, &i, data);
	cylinder->norm_vec.y = ft_prepare_to_convert_atof(line, &i, data);
	cylinder->norm_vec.z = ft_prepare_to_convert_atof(line, &i, data);
	if ((cylinder->norm_vec.x < -1 || cylinder->norm_vec.x > 1) || (cylinder->norm_vec.y < -1
		|| cylinder->norm_vec.y > 1) || (cylinder->norm_vec.z < -1 || cylinder->norm_vec.z > 1))
		ft_parsing_error_handler(line, data);
	cylinder->diameter = ft_prepare_to_convert_atof(line, &i, data);
	if (cylinder->diameter <= 0.0)
		ft_parsing_error_handler(line, data);
	cylinder->height = ft_prepare_to_convert_atof(line, &i, data);
	if (cylinder->height <= 0.0)
		ft_parsing_error_handler(line, data);
	cylinder->color.R = (int) ft_prepare_to_convert_atoi(line, &i, data);
	cylinder->color.G = (int) ft_prepare_to_convert_atoi(line, &i, data);
	cylinder->color.B = (int) ft_prepare_to_convert_atoi(line, &i, data);
	if ((cylinder->color.R < 0 || cylinder->color.R > 255) || (cylinder->color.G < 0
		|| cylinder->color.G > 255) || (cylinder->color.B < 0 || cylinder->color.B > 255))
		ft_parsing_error_handler(line, data);
	if (line[i] != '\n' && line[i] != '\0')
		ft_parsing_error_handler(line, data);
	if (cylinder_addback(&(data->obj), cylinder) == 1)
		ft_parsing_error_handler(line, data);
}
