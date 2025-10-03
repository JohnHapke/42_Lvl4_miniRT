/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:13:04 by iherman-          #+#    #+#             */
/*   Updated: 2025/10/03 11:47:25 by iherman-         ###   ########.fr       */
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
	data->mlx_win = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT", false);
	data->mlx_img = mlx_new_image(data->mlx_win, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->mlx_img)
	{
		write(2, "Failed to create mlx image", 26);
		return (1);
	}
	mlx_loop_hook(data->mlx_win, &raytracer, (void *)data);
	mlx_loop(data->mlx_win);
	mlx_terminate(data->mlx_win);
	ft_free_parsing(NULL, data);
	return (0);
}
