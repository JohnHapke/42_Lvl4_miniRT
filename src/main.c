/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:13:04 by iherman-          #+#    #+#             */
/*   Updated: 2025/10/19 18:23:07 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	key_callback(mlx_key_data_t keydata, void *param)
{
	t_rt_data	*data = (t_rt_data *)param;
	
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(data->mlx_win);
		ft_free_parsing(NULL, data);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	t_rt_data	*data;

	if (argc != 2)
	{
		perror("Error: Usage: Must provide .rt scene");
		return (1);
	}
	data = (t_rt_data *)ft_calloc(1, sizeof(t_rt_data));
	if (!data)
		ft_parsing_error_handler(NULL, data);
	ft_parsing_handler(argv[1], data);
	data->mlx_win = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT", false);
	data->mlx_img = mlx_new_image(data->mlx_win, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->mlx_img)
	{
		perror("Failed to create mlx image");
		return (1);
	}
	mlx_loop_hook(data->mlx_win, &raytracer, (void *)data);
	mlx_key_hook(data->mlx_win, &key_callback, data);
	mlx_loop(data->mlx_win);
	mlx_terminate(data->mlx_win);
	ft_free_parsing(NULL, data);
	return (0);
}
