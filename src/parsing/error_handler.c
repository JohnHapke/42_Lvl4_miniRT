/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:29:28 by johnhapke         #+#    #+#             */
/*   Updated: 2025/08/22 14:58:15 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void ft_parsing_error_handler(t_rt_data *data)
{
	ft_free_parsing(data);
	printf("Error\n");
	exit(1);
}

void	ft_free_parsing(t_rt_data*data)
{
	if (data->sphere)
		free(data->sphere);
	if (data->plane)
		free(data->plane);
	if (data->cylinder)
		free(data->cylinder);
}