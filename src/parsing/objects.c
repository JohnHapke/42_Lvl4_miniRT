/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:48:11 by johnhapke         #+#    #+#             */
/*   Updated: 2025/10/22 12:25:57 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_parse_sphere(char *line, t_rt_data *data)
{
	int			i;
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		ft_parsing_error_handler(line, data);
	i = 0;
	sphere->pos = convert_vec3(line, &i, data);
	sphere->diameter = ft_prepare_to_convert_atof(line, &i, data);
	sphere->color.x = (int) ft_prepare_to_convert_atoi(line, &i, data);
	sphere->color.y = (int) ft_prepare_to_convert_atoi(line, &i, data);
	sphere->color.z = (int) ft_prepare_to_convert_atoi(line, &i, data);

	if (sphere_addback(&(data->obj), sphere) == 1)
		ft_parsing_error_handler(line, data);
	if (sphere->diameter <= 0.0)
		ft_parsing_error_handler(line, data);
	if (!in_range(sphere->color, 0, 255))
		ft_parsing_error_handler(line, data);
	if (line[i] != '\n' && line[i] != '\0')
		ft_parsing_error_handler(line, data);
}

void	ft_parse_plane(char *line, t_rt_data *data)
{
	int		i;
	t_plane	*plane;

	i = 0;
	plane = malloc(sizeof(t_plane));
	if (!plane)
		ft_parsing_error_handler(line, data);
	plane->pos = convert_vec3(line, &i, data);
	plane->norm_vec = convert_vec3(line, &i, data);
	plane->norm_vec = normalize(plane->norm_vec);
	plane->color.x = (int) ft_prepare_to_convert_atoi(line, &i, data);
	plane->color.y = (int) ft_prepare_to_convert_atoi(line, &i, data);
	plane->color.z = (int) ft_prepare_to_convert_atoi(line, &i, data);

	if (plane_addback(&(data->obj), plane) == 1)
		ft_parsing_error_handler(line, data);
	if (!is_normalized(plane->norm_vec))
		ft_parsing_error_handler(line, data);
	if (!in_range(plane->color, 0, 255))
		ft_parsing_error_handler(line, data);
	if (line[i] != '\n' && line[i] != '\0')
		ft_parsing_error_handler(line, data);
}

void	ft_parse_cylinder(char *line, t_rt_data *data)
{
	int			i;
	t_cylinder	*cylinder;

	i = 0;
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		ft_parsing_error_handler(line, data);
	cylinder->pos = convert_vec3(line, &i, data);
	cylinder->norm_vec = convert_vec3(line, &i, data);
	cylinder->diameter = ft_prepare_to_convert_atof(line, &i, data);
	cylinder->height = ft_prepare_to_convert_atof(line, &i, data);
	cylinder->color.x = (int) ft_prepare_to_convert_atoi(line, &i, data);
	cylinder->color.y = (int) ft_prepare_to_convert_atoi(line, &i, data);
	cylinder->color.z = (int) ft_prepare_to_convert_atoi(line, &i, data);
	if (cylinder_addback(&data->obj, cylinder) == 1)
		ft_parsing_error_handler(line, data);
	if (!is_normalized(cylinder->norm_vec))
		ft_parsing_error_handler(line, data);
	cylinder->norm_vec = normalize(cylinder->norm_vec);
	if (cylinder->diameter <= 0.0)
		ft_parsing_error_handler(line, data);
	if (cylinder->height <= 0.0)
		ft_parsing_error_handler(line, data);
	if (!in_range(cylinder->color, 0, 255))
		ft_parsing_error_handler(line, data);
	if (line[i] != '\n' && line[i] != '\0')
		ft_parsing_error_handler(line, data);
}
