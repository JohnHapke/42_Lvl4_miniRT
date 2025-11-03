/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:19:03 by iherman-          #+#    #+#             */
/*   Updated: 2025/11/03 11:17:58 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	facilitate_input_line(char *line, t_rt_data *data)
{
	if (line[0] == '#')
		return ;
	if (ft_strncmp(line, "A", 1) == 0)
		parse_ambient_lighting(line, data);
	else if (ft_strncmp(line, "C", 1) == 0)
		parse_camera(line, data);
	else if (ft_strncmp(line, "L", 1) == 0)
		parse_light(line, data);
	else if (ft_strncmp(line, "sp", 2) == 0)
		parse_sphere(line, data);
	else if (ft_strncmp(line, "pl", 2) == 0)
		parse_plane(line, data);
	else if (ft_strncmp(line, "cy", 2) == 0)
		parse_cylinder(line, data);
}

void	parsing_handler(char *file, t_rt_data *data)
{
	char	*line;
	int		fd;

	control_type_identifier(file, data);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_parsing_error_handler(NULL, "Internal: failed to open file", data);
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		facilitate_input_line(line, data);
		free(line);
	}
	close(fd);
	ft_get_next_line(-1);
}
