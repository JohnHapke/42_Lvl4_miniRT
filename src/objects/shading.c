/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:00:34 by johnhapke         #+#    #+#             */
/*   Updated: 2025/11/04 13:14:26 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	reaches_light(const t_hitinfo *prev_hitinfo, t_rt_data *data)
{
	t_hitinfo	hitinfo;
	t_ray		ray;
	t_obj		*obj;
	double		light_t;

	obj = data->obj;
	ray.direction = vector_subtract(data->light.light_point, prev_hitinfo->pos);
	light_t = vector_length(ray.direction);
	ray.direction = normalize(ray.direction);
	ray.origin = vector_add(prev_hitinfo->pos,
			vector_multiply(prev_hitinfo->surface_dir, EPSILON));
	while (obj != NULL)
	{
		if (obj->check_intersection(obj->obj, ray, &hitinfo))
		{
			if (hitinfo.t > 0 && hitinfo.t < light_t)
				return (false);
		}
		obj = obj->next;
	}
	return (true);
}

unsigned int	format_color(t_vec3 color)
{
	return ((int)(fmin(1.0, color.x) * 255.0) << 24
		| (int)(fmin(1.0, color.y) * 255.0) << 16
		| (int)(fmin(1.0, color.z) * 255.0) << 8
		| 255);
}

t_vec3	calculate_ambient(const t_hitinfo *hitinfo, t_rt_data *data)
{
	t_vec3	ambient_color;

	ambient_color.x = fmin(1.0, ((hitinfo->obj_color.x
					* data->amb_light.color.x) * data->amb_light.light_ratio));
	ambient_color.y = fmin(1.0, ((hitinfo->obj_color.y
					* data->amb_light.color.y) * data->amb_light.light_ratio));
	ambient_color.z = fmin(1.0, ((hitinfo->obj_color.z
					* data->amb_light.color.z) * data->amb_light.light_ratio));
	return (ambient_color);
}

static inline t_vec3	vector_hadamard(t_vec3 a, t_vec3 b)
{
	t_vec3	res;

	res.x = a.x * b.x;
	res.y = a.y * b.y;
	res.z = a.z * b.z;
	return (res);
}

unsigned int	calculate_color(const t_hitinfo *hitinfo, t_rt_data *data)
{
	t_vec3	ambient_color;
	t_vec3	diffuse_color;
	t_vec3	final_color;
	t_vec3	light_dir;
	double	diffuse_intensity;

	ambient_color = calculate_ambient(hitinfo, data);
	final_color = ambient_color;
	if (reaches_light(hitinfo, data))
	{
		light_dir
			= normalize(vector_subtract(data->light.light_point, hitinfo->pos));
		diffuse_intensity
			= fmax(0.0, vector_dot(hitinfo->surface_dir, light_dir))
			* data->light.light_ratio;
		diffuse_color = vector_hadamard(hitinfo->obj_color, data->light.color);
		diffuse_color = vector_multiply(diffuse_color, diffuse_intensity);
		final_color = vector_add(final_color, diffuse_color);
	}
	return (format_color(final_color));
}
