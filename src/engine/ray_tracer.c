/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:07:06 by iherman-          #+#    #+#             */
/*   Updated: 2025/10/14 11:35:20 by iherman-         ###   ########.fr       */
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
		if (obj->fct_ptr(obj->obj, ray, &hitinfo) && hitinfo.t < best_hit.t)
		{
			best_hit = hitinfo;
			//printf("t= %f\n", best_hit.t);
			hit_found = true;
		}
		obj = obj->next;
	}
	if (hit_found)
	{
		unsigned int color = calculate_color(&best_hit, data);
		//printf("color: %u\n", color);
		return (color);
	}
	return (0 << 24 | 0 << 16 | 0 << 8 | 255);
}

t_ray	generate_ray(t_rt_data *data, int screenX, int screenY)
{
	t_ray ray;

	double aspectRatio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	double ndcX = (2.0 * (screenX + 0.5) / WINDOW_WIDTH) - 1.0;
	double ndcY = 1.0 - (2.0 * (screenY + 0.5) / WINDOW_HEIGHT);
	double fovAdjust = tan(data->camera.fov * 0.5 * 3.14 / 180.0);

	t_vec3 rayDir = vector_add(
		data->camera.norm_vec,
		vector_add(
			vector_multiply(data->camera.right, ndcX * aspectRatio * fovAdjust),
			vector_multiply(data->camera.up, ndcY * fovAdjust)));
	ray.origin = data->camera.viewpoint;
	ray.direction = normalize(rayDir);
	return (ray);
}

unsigned int	shoot_ray(t_rt_data *data, int screen_x, int screen_y)
{
	t_ray			ray;

	ray = generate_ray(data, screen_x, screen_y);
	//printf("ray generated \n"); -> functional
	return (intersect_test(ray, data));
}

void	raytracer(void *tmp_data)
{
	t_rt_data		*data;
	unsigned int	color;
	int				screen_x;
	int				screen_y;

	data = (t_rt_data *)tmp_data;
	screen_x = 0;
	screen_y = 0;
	while (screen_x < WINDOW_WIDTH)
	{
		while (screen_y < WINDOW_HEIGHT)
		{
			color = shoot_ray(data, screen_x, screen_y);
			mlx_put_pixel(data->mlx_img, screen_x, screen_y, color);
			screen_y++;
		}
		screen_y = 0;
		screen_x++;
	}
	mlx_image_to_window(data->mlx_win, data->mlx_img, 0, 0);
}
