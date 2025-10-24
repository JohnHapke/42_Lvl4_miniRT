/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:07:06 by iherman-          #+#    #+#             */
/*   Updated: 2025/10/24 21:27:17 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static unsigned int	intersect_test(t_ray ray, t_rt_data *data)
{
	t_hitinfo	hitinfo;
	t_hitinfo	best_hit;
	bool		hit_found;
	t_obj		*obj;

	obj = data->obj;
	hit_found = false;
	best_hit.t = INFINITY;
	while (obj != NULL)
	{
		if (obj->check_intersection(obj->obj, ray, &hitinfo) && hitinfo.t < best_hit.t)
		{
			best_hit = hitinfo;
			hit_found = true;
		}
		obj = obj->next;
	}
	if (hit_found)
	{
		unsigned int color = calculate_color(&best_hit, data);
		return (color);
	}
	return (0 << 24 | 0 << 16 | 0 << 8 | 255);
}

t_ray	generate_ray(t_rt_data *data, int screen_x, int screen_y)
{
	t_ray ray;
	const double ndcX = (2.0 * (screen_x + 0.5) / WINDOW_WIDTH) - 1.0;
	const double ndcY = 1.0 - (2.0 * (screen_y + 0.5) / WINDOW_HEIGHT);

	t_vec3 rayDir = vector_add(
		data->camera.norm_vec,
		vector_add(
			vector_multiply(data->camera.right, ndcX * data->camera.aspect_ratio * data->camera.fov_adjust),
			vector_multiply(data->camera.up, ndcY * data->camera.fov_adjust)));
	ray.origin = data->camera.viewpoint;
	ray.direction = normalize(rayDir);
	return (ray);
}

void	raytracer(void *tmp_data)
{
	t_rt_data		*data;
	unsigned int	color;
	int				screen_x;
	int				screen_y;
	t_ray			ray;

	data = (t_rt_data *)tmp_data;
	screen_x = 0;
	screen_y = 0;
	while (screen_x < WINDOW_WIDTH)
	{
		while (screen_y < WINDOW_HEIGHT)
		{
			ray = generate_ray(data, screen_x, screen_y);
			color = intersect_test(ray, data);
			mlx_put_pixel(data->mlx_img, screen_x, screen_y, color);
			screen_y++;
		}
		screen_y = 0;
		screen_x++;
	}
	mlx_image_to_window(data->mlx_win, data->mlx_img, 0, 0);
}
