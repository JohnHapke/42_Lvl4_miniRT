/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:03:21 by johnhapke         #+#    #+#             */
/*   Updated: 2025/08/19 11:45:58 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_parse_ambient_lighting(char *line, t_rt_data *data)
{
	(void) line; (void) data;
	printf("ambient light\n");
}

void	ft_parse_camera(char *line, t_rt_data *data)
{
	(void) line; (void) data;
	printf("camera\n");
}

void	ft_parse_light(char *line, t_rt_data *data)
{
	(void) line; (void) data;
	printf("light\n");
}
