/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:17:20 by jhapke            #+#    #+#             */
/*   Updated: 2025/11/04 12:36:03 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rotate_y(t_camera *camera, double angle_deg)
{
	double	rad;
	double	cos_a;
	double	sin_a;

	rad = angle_deg * M_PI / 180.0;
	cos_a = cos(rad);
	sin_a = sin(rad);
	camera->norm_vec.x = camera->norm_vec.x
		* cos_a + camera->norm_vec.z * sin_a;
	camera->norm_vec.z = -camera->norm_vec.x
		* sin_a + camera->norm_vec.z * cos_a;
	camera->right
		= normalize(vector_cross((t_vec3){0, 1, 0}, camera->norm_vec));
	camera->up = normalize(vector_cross(camera->norm_vec, camera->right));
	camera->norm_vec = normalize(camera->norm_vec);
}

static bool	iskey(mlx_key_data_t keydata, keys_t key)
{
	if (keydata.key == key
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		return (true);
	return (false);
}

void	move_camera(mlx_key_data_t keydata, t_camera *camera)
{
	float	move_speed;
	float	camera_speed;

	move_speed = 5;
	camera_speed = 5;
	if (iskey(keydata, MLX_KEY_RIGHT))
		camera->viewpoint = vector_add(camera->viewpoint,
				vector_multiply(camera->right, move_speed));
	else if (iskey(keydata, MLX_KEY_LEFT))
		camera->viewpoint = vector_add(camera->viewpoint,
				vector_multiply(vector_multiply(camera->right, -1),
					move_speed));
	else if (iskey(keydata, MLX_KEY_UP))
		camera->viewpoint = vector_add(camera->viewpoint,
				vector_multiply(camera->norm_vec, move_speed));
	else if (iskey(keydata, MLX_KEY_DOWN))
		camera->viewpoint = vector_add(camera->viewpoint,
				vector_multiply(vector_multiply(camera->norm_vec, -1),
					move_speed));
	else if (iskey(keydata, MLX_KEY_A))
		rotate_y(camera, -camera_speed);
	else if (iskey(keydata, MLX_KEY_D))
		rotate_y(camera, camera_speed);
}
