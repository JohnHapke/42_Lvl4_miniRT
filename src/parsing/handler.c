/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:19:03 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/20 11:27:56 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
1. control if the line starts with a A, C, L, sp, pl, cy
*/

static int ft_control_type_identifier(char *file)
{
	int		fd;
	char	*line;
	int		A;
	int		C;
	int		L;

	A = 0;
	C = 0;
	L = 0;
	fd = open(file, O_RDONLY);
	if (!fd)
		return (1);
	printf("type_control \n");
	line = ft_get_next_line(fd);
	printf("type_control line\n");
	if (!line)
		return (1);
	while (line)
	{
		printf("type_control while\n");
		if (!ft_isalpha(line[0]) && ft_strncmp(line, "\n", 1) != 0)
		return (1);
		else if (ft_strncmp(line, "A", 1) == 0)
			A++;
		else if (ft_strncmp(line, "C", 1) == 0)
			C++;
		else if (ft_strncmp(line, "L", 1) == 0)
			L++;
		else if (ft_strncmp(line, "sp", 2) != 0 && ft_strncmp(line, "pl", 2) != 0
			&& ft_strncmp(line, "cy", 2) != 0 && ft_strncmp(line, "\n", 1) != 0)
			return (1);
		printf("A:%i, C:%i, L:%i \n", A, C, L);
		line = ft_get_next_line(fd);
		if (!line)
			break ;
	}
	if (A > 1 || C > 1 || L > 1)
		return (1);
	return (0);
}

static void	ft_parsing_facilitator(char *line, t_rt_data *data)
{
	printf("facilitator \n");
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

	printf("handler \n");
	if (ft_control_type_identifier(file))
		ft_parsing_error_handler();
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_parsing_error_handler();
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		ft_parsing_facilitator(line, data);
	}
	line = ft_get_next_line(fd);
		if (!line)
			return ;
	ft_parsing_error_handler();
}
