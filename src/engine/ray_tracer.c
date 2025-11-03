/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:07:06 by iherman-          #+#    #+#             */
/*   Updated: 2025/11/03 10:58:34 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static unsigned int	intersect_test(t_ray ray, t_rt_data *data)
{
	t_hitinfo		hitinfo;
	t_hitinfo		best_hit;
	bool			hit_found;
	t_obj			*obj;
	unsigned int	color;

	obj = data->obj;
	hit_found = false;
	best_hit.t = INFINITY;
	while (obj != NULL)
	{
		if (obj->check_intersection(obj->obj, ray, &hitinfo)
			&& hitinfo.t < best_hit.t)
		{
			best_hit = hitinfo;
			hit_found = true;
		}
		obj = obj->next;
	}
	if (hit_found)
	{
		color = calculate_color(&best_hit, data);
		return (color);
	}
	return (0 << 24 | 0 << 16 | 0 << 8 | 255);
}

t_ray	generate_ray(t_rt_data *data, int screen_x, int screen_y)
{
	t_ray	ray;
	double	ndc_x;
	double	ndc_y;
	t_vec3	ray_dir;

	ndc_x = (2.0 * (screen_x + 0.5) / WINDOW_WIDTH) - 1.0;
	ndc_y = 1.0 - (2.0 * (screen_y + 0.5) / WINDOW_HEIGHT);
	ray_dir = vector_add(data->camera.norm_vec, vector_add(
				vector_multiply(data->camera.right, ndc_x
					* data->camera.aspect_ratio * data->camera.fov_adjust),
				vector_multiply(data->camera.up, ndc_y
					* data->camera.fov_adjust)));
	ray.origin = data->camera.viewpoint;
	ray.direction = normalize(ray_dir);
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
