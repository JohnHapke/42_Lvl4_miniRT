/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:40:59 by iherman-          #+#    #+#             */
/*   Updated: 2025/10/21 22:07:22 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	exit_mlx(void *param)
{
	t_rt_data	*data;

	data = (t_rt_data *)param;
	mlx_delete_image(data->mlx_win, data->mlx_img);
}

void	key_callback(mlx_key_data_t keydata, void *param)
{
	t_rt_data	*data = (t_rt_data *)param;
	
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		exit_mlx(data);
		mlx_terminate(data->mlx_win);
		ft_free_parsing(NULL, data);
		exit(0);
	}
}

void	mlx_handler(t_rt_data *data)
{
	data->mlx_win = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT", false);
	if (!data->mlx_win)
	{
		write(2, "Error: Internal: Failed to create mlx image", 33);
		ft_free_parsing(NULL, data);
		exit (1);
	}
	data->mlx_img = mlx_new_image(data->mlx_win, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->mlx_img)
	{
		write(2, "Error: Internal: Failed to create mlx image", 33);
		mlx_terminate(data->mlx_win);
		ft_free_parsing(NULL, data);
		exit (1);
	}
	mlx_loop_hook(data->mlx_win, &raytracer, (void *)data);
	mlx_key_hook(data->mlx_win, &key_callback, data);
	mlx_close_hook(data->mlx_win, &exit_mlx, data);
}
