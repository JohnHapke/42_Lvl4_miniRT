/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:29:28 by johnhapke         #+#    #+#             */
/*   Updated: 2025/08/25 11:35:00 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void ft_parsing_error_handler(char *line, t_rt_data *data)
{
	ft_free_parsing(line, data);
	printf("Error\n");
	exit(1);
}

void	ft_free_parsing(char *line, t_rt_data *data)
{
	ft_get_next_line(-1);
	if (line)
		free(line);
	if (data->sphere)
		free(data->sphere);
	if (data->plane)
		free(data->plane);
	if (data->cylinder)
		free(data->cylinder);
	if (data)
		free(data);
}