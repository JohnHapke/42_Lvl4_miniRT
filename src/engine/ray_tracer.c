/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:07:06 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/29 09:34:39 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static unsigned int	intersect_test(t_ray ray, t_rt_data *data)
{
	t_hitinfo	hitinfo;
	int			hit;
	t_hitinfo	best_hit;
	bool		hit_found;
	t_obj		*obj;

	obj = data->obj;
	hit_found = false;
	best_hit.t = INFINITY;
	while (obj != NULL)
	{
		hit = obj->fct_ptr(obj->obj, ray, &hitinfo);
		if (hit == 1 && (hitinfo.t > 0 && hitinfo.t < best_hit.t))
		{
			best_hit = hitinfo;
			//printf("t= %f\n", best_hit.t);
			hit_found = true;
		}
		obj = obj->next;
	}
	if (hit_found == true)
	{
		unsigned int color = calculate_color(best_hit, data);
		printf("color: %u\n", color);
		return (color);
	}
	return (0 << 24 | 0 << 16 | 0 << 8 | 255);
}

t_ray	generate_ray(t_rt_data *data, int screenX, int screenY)
{
	t_ray ray;

	double aspectRatio = (double)800 / (double)600;
	double ndcX = (2.0 * (screenX + 0.5) / 800) - 1.0;
	double ndcY = 1.0 - (2.0 * (screenY + 0.5) / 600);
	double fovAdjust = tan(data->camera.fov * 0.5 * 3.14 / 180.0);

	t_vec3 rayDir = vector_add(
		data->camera.norm_vec,
		vector_add(
			vector_multiply(data->camera.right, ndcX * aspectRatio * fovAdjust),
			vector_multiply(data->camera.up, ndcY * fovAdjust)));
	printf("ray: x=%f, y=%f, z=%f\n", rayDir.x, rayDir.y, rayDir.z);
	ray.origin = data->camera.viewpoint;
	ray.direction = normalize(rayDir);
	return (ray);
}

unsigned int	shoot_ray(t_rt_data *data, int screen_x, int screen_y)
{
	t_ray			ray;
	//unsigned char	alpha;

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
	mlx_image_t		*img;

	data = (t_rt_data *)tmp_data;
	img	= mlx_new_image(data->mlx_win, 800, 600);
	if (!img)
		return ;
	screen_x = 0;
	screen_y = 0;
	while (screen_x < 800)
	{
		while (screen_y < 600)
		{
			color = shoot_ray(data, screen_x, screen_y);
			mlx_put_pixel(img, screen_x, screen_y, color);
			screen_y++;
		}
		screen_y = 0;
		screen_x++;
	}
	mlx_image_to_window(data->mlx_win, img, 0, 0);
	// memory leaks :D
}
