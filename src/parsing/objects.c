/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:48:11 by johnhapke         #+#    #+#             */
/*   Updated: 2025/10/07 15:15:16 by iherman-         ###   ########.fr       */
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
	sphere->color.x = (int) ft_prepare_to_convert_atoi(line, &i, data);
	sphere->color.y = (int) ft_prepare_to_convert_atoi(line, &i, data);
	sphere->color.z = (int) ft_prepare_to_convert_atoi(line, &i, data);
	if ((sphere->color.x < 0 || sphere->color.x > 255) || (sphere->color.y < 0
		|| sphere->color.y > 255) || (sphere->color.z < 0 || sphere->color.z > 255))
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
		printf("Plane 1");
	plane->pos.x = ft_prepare_to_convert_atof(line, &i, data);
	plane->pos.y = ft_prepare_to_convert_atof(line, &i, data);
	plane->pos.z = ft_prepare_to_convert_atof(line, &i, data);
	plane->norm_vec.x = ft_prepare_to_convert_atof(line, &i, data);
	plane->norm_vec.y = ft_prepare_to_convert_atof(line, &i, data);
	plane->norm_vec.z = ft_prepare_to_convert_atof(line, &i, data);
	if ((plane->norm_vec.x < -1 || plane->norm_vec.x > 1) || (plane->norm_vec.y < -1
		|| plane->norm_vec.y > 1) || (plane->norm_vec.z < -1 || plane->norm_vec.z > 1))
		printf("Plane 2");
	plane->color.x = (int) ft_prepare_to_convert_atoi(line, &i, data);
	plane->color.y = (int) ft_prepare_to_convert_atoi(line, &i, data);
	plane->color.z = (int) ft_prepare_to_convert_atoi(line, &i, data);
	if ((plane->color.x < 0 || plane->color.x > 255) || (plane->color.y < 0
		|| plane->color.y > 255) || (plane->color.z < 0 || plane->color.z > 255))
		printf("Plane 3");
	if (line[i] != '\n' && line[i] != '\0')
		printf("Plane 4");
	if (plane_addback(&(data->obj), plane) == 1)
		printf("Plane 5");
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
	cylinder->color.x = (int) ft_prepare_to_convert_atoi(line, &i, data);
	cylinder->color.y = (int) ft_prepare_to_convert_atoi(line, &i, data);
	cylinder->color.z = (int) ft_prepare_to_convert_atoi(line, &i, data);
	if ((cylinder->color.x < 0 || cylinder->color.x > 255) || (cylinder->color.y < 0
		|| cylinder->color.y > 255) || (cylinder->color.z < 0 || cylinder->color.z > 255))
		ft_parsing_error_handler(line, data);
	if (line[i] != '\n' && line[i] != '\0')
		ft_parsing_error_handler(line, data);
	if (cylinder_addback(&(data->obj), cylinder) == 1)
		ft_parsing_error_handler(line, data);
}
