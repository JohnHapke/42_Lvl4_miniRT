/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:19:03 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/25 13:04:43 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_facilitate_input_line(char *line, t_rt_data *data)
{
	if (ft_strncmp(line, "A", 1) == 0)
		ft_parse_ambient_lighting(line, data);
	else if (ft_strncmp(line, "C", 1) == 0)
		ft_parse_camera(line, data);
	else if (ft_strncmp(line, "L", 1) == 0)
		ft_parse_light(line, data);
	else if (ft_strncmp(line, "sp", 2) == 0)
		ft_parse_sphere(line, data);
	else if (ft_strncmp(line, "pl", 2) == 0)
		ft_parse_plane(line, data);
	else if (ft_strncmp(line, "cy", 2) == 0)
		ft_parse_cylinder(line, data);
}

void	ft_parsing_handler(char *file, t_rt_data *data)
{
	char	*line;
	int		fd;

	ft_control_type_identifier(file, data);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_parsing_error_handler(NULL, data);
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		ft_facilitate_input_line(line, data);
		free(line);
	}
	close(fd);
	ft_get_next_line(-1);
}
