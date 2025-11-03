/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:13:04 by iherman-          #+#    #+#             */
/*   Updated: 2025/11/03 11:19:54 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_rt_data	data;

	if (argc != 2)
	{
		write(2, "Error: Usage: Must provide .rt scene\n", 37);
		return (1);
	}
	ft_bzero(&data, sizeof(t_rt_data));
	parsing_handler(argv[1], &data);
	mlx_handler(&data);
	mlx_loop(data.mlx_win);
	free_parsing(NULL, &data);
	return (0);
}
