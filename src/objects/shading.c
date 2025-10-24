/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:00:34 by johnhapke         #+#    #+#             */
/*   Updated: 2025/10/24 22:58:09 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// ToDo: ray from t to light has to be calculated to see if there is an object in between

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
	if (vector_dot(ray.direction, prev_hitinfo->surface_dir) < 0)
		return (false);
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

t_vec3	calculate_specular(const t_hitinfo *hitinfo, const t_rt_data *data)
{
	t_vec3	l;
	double	ndotl;
	double	rdotv;
	double	specular_intensity;

	if (SPECULAR_M == -1)
		return ((t_vec3){0,0,0});
	l = normalize(vector_subtract(data->light.light_point,
				hitinfo->pos));
	ndotl = fmax(0, vector_dot(hitinfo->surface_dir, l));
	rdotv = fmax(0, vector_dot(vector_subtract
				(vector_multiply(hitinfo->surface_dir, 2 * ndotl), l),
				normalize(vector_subtract(data->camera.viewpoint,
						hitinfo->pos))));
	specular_intensity = pow(rdotv, SPECULAR_M);
	return (vector_multiply((t_vec3){255, 255, 255}, specular_intensity));
}

unsigned int	format_color(t_vec3 color)
{
	return ((int)color.x << 24 | (int)color.y << 16 | (int)color.z << 8 | 255);
}

unsigned int	calculate_color(const t_hitinfo *hitinfo, t_rt_data *data)
{
	t_vec3	ambient_color;
	t_vec3	diffuse_color;
	t_vec3	specular_color;
	t_vec3	final_color;
	double	diffuse_intensity;

	ambient_color = vector_multiply(hitinfo->obj_color,
			data->amb_light.light_ratio);
	if (reaches_light(hitinfo, data))
	{
		diffuse_intensity = fmax(0, vector_dot(hitinfo->surface_dir,
					normalize(vector_subtract(data->light.light_point,
							hitinfo->pos))) * data->light.light_ratio);
		diffuse_color = vector_multiply(hitinfo->obj_color, diffuse_intensity);
		specular_color = calculate_specular(hitinfo, data);
		final_color.x = (int)fmin(255.0, ambient_color.x
				+ diffuse_color.x + specular_color.x);
		final_color.y = (int)fmin(255.0, ambient_color.y
				+ diffuse_color.y + specular_color.y);
		final_color.z = (int)fmin(255.0, ambient_color.z
				+ diffuse_color.z + specular_color.z);
		return (format_color(final_color));
	}
	return (format_color(ambient_color));
}
