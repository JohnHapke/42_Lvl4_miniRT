/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:40:59 by iherman-          #+#    #+#             */
/*   Updated: 2025/10/28 17:43:59 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	exit_mlx(void *param)
{
	t_rt_data	*data;

	data = (t_rt_data *)param;
	mlx_delete_image(data->mlx_win, data->mlx_img);
}

void rotate_y(t_camera *camera, double angle_deg)
{
	const double rad = angle_deg * M_PI / 180.0;
	const double cos_a = cos(rad);
	const double sin_a = sin(rad);

	camera->norm_vec.x = camera->norm_vec.x * cos_a + camera->norm_vec.z * sin_a;
	camera->norm_vec.z = -camera->norm_vec.x * sin_a + camera->norm_vec.z * cos_a;
	camera->right = normalize(vector_cross((t_vec3){0,1,0}, camera->norm_vec));
	camera->up = normalize(vector_cross(camera->norm_vec, camera->right));
	camera->norm_vec = normalize(camera->norm_vec);
}

void	attempt_move_camera(mlx_key_data_t keydata, t_camera *camera)
{
	const float			move_speed = 5;
	const float			camera_speed = 5;

	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		camera->viewpoint = vector_add(camera->viewpoint, vector_multiply(camera->right, move_speed));
	else if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		camera->viewpoint = vector_add(camera->viewpoint, vector_multiply(vector_multiply(camera->right, -1), move_speed));
	else if (keydata.key == MLX_KEY_UP && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		camera->viewpoint = vector_add(camera->viewpoint, vector_multiply(camera->norm_vec, move_speed));
	else if (keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		camera->viewpoint = vector_add(camera->viewpoint, vector_multiply(vector_multiply(camera->norm_vec, -1), move_speed));
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		rotate_y(camera, -camera_speed);
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		rotate_y(camera, camera_speed);
}

void	key_callback(mlx_key_data_t keydata, void *param)
{
	t_rt_data			*data = (t_rt_data *)param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		exit_mlx(data);
		mlx_terminate(data->mlx_win);
		ft_free_parsing(NULL, data);
		exit(0);
	}
	else
		attempt_move_camera(keydata, &data->camera);
}

void	mlx_handler(t_rt_data *data)
{
	data->mlx_win = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT", false);
	if (!data->mlx_win)
	{
		(void)write(2, "Error: Internal: Failed to create mlx image", 33);
		ft_free_parsing(NULL, data);
		exit (1);
	}
	data->mlx_img = mlx_new_image(data->mlx_win, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->mlx_img)
	{
		(void)write(2, "Error: Internal: Failed to create mlx image", 33);
		mlx_terminate(data->mlx_win);
		ft_free_parsing(NULL, data);
		exit (1);
	}
	mlx_loop_hook(data->mlx_win, &raytracer, (void *)data);
	mlx_key_hook(data->mlx_win, &key_callback, data);
	mlx_close_hook(data->mlx_win, &exit_mlx, data);
}
