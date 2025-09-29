/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:13:04 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/27 15:22:09 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_rt_data	*data;

	data = (t_rt_data *)ft_calloc(1, sizeof(t_rt_data));
	if (!data)
		ft_parsing_error_handler(NULL, data);
	(void) argc; (void) argv;
	ft_parsing_handler(argv[1], data);
	data->mlx_win = mlx_init(800, 600, "miniRT", false);
	mlx_loop_hook(data->mlx_win, &raytracer, (void *)data);
	mlx_loop(data->mlx_win);
	mlx_terminate(data->mlx_win);
	ft_free_parsing(NULL, data);
	return (0);
}
