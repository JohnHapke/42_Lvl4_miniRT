/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:40:59 by iherman-          #+#    #+#             */
/*   Updated: 2025/11/04 12:35:41 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	exit_mlx(void *param)
{
	t_rt_data	*data;

	data = (t_rt_data *)param;
	mlx_delete_image(data->mlx_win, data->mlx_img);
}

static void	key_callback(mlx_key_data_t keydata, void *param)
{
	t_rt_data	*data;

	data = (t_rt_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		exit_mlx(data);
		mlx_terminate(data->mlx_win);
		free_parsing(NULL, data);
		exit(0);
	}
	else
		move_camera(keydata, &data->camera);
}

void	mlx_handler(t_rt_data *data)
{
	data->mlx_win = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT", false);
	if (!data->mlx_win)
	{
		(void)write(2, "Error: Internal: Failed to create mlx image", 33);
		free_parsing(NULL, data);
		exit (1);
	}
	data->mlx_img = mlx_new_image(data->mlx_win, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->mlx_img)
	{
		(void)write(2, "Error: Internal: Failed to create mlx image", 33);
		mlx_terminate(data->mlx_win);
		free_parsing(NULL, data);
		exit (1);
	}
	mlx_loop_hook(data->mlx_win, &raytracer, (void *)data);
	mlx_key_hook(data->mlx_win, &key_callback, data);
	mlx_close_hook(data->mlx_win, &exit_mlx, data);
}
