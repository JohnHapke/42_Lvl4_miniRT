/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:00:34 by johnhapke         #+#    #+#             */
/*   Updated: 2025/10/07 15:32:47 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// ToDo: ray from t to light has to be calculated to see if there is an object in between

static bool	reaches_light(const t_hitinfo *prev_hitinfo, t_rt_data *data)
{
	t_hitinfo	hitinfo;
	t_hitinfo	best_hit;
	t_ray		ray;
	t_obj		*obj;
	double		light_t;

	obj = data->obj;
	best_hit.t = INFINITY;
	ray.direction = vector_subtract(data->light.light_point, prev_hitinfo->pos);
	light_t = vector_length(ray.direction);
	ray.direction = normalize(ray.direction);
	ray.origin = vector_add(prev_hitinfo->pos, vector_multiply(prev_hitinfo->surface_dir, EPSILON));
	if (vector_dot(ray.direction, prev_hitinfo->surface_dir) < 0)
		return (false);
	while (obj != NULL)
	{
		obj->fct_ptr(obj->obj, ray, &hitinfo);
		if ((hitinfo.t > 0 && hitinfo.t < best_hit.t))
			best_hit = hitinfo;
		obj = obj->next;
	}
	if (best_hit.t > 0 && best_hit.t < light_t)
		return (false);
	return (true);
}

unsigned int	calculate_color(const t_hitinfo *hitinfo, t_rt_data *data)
{
	t_vec3	ambient_color;
	t_vec3	diffuse_color;
	double	diffuse_intensity;
	t_vec3	final_color;
	bool	is_lit;

	is_lit = reaches_light(hitinfo, data);


	// ambient color
	ambient_color = vector_multiply(hitinfo->obj_color, data->amb_light.light_ratio);

	// diffuse intensity
	diffuse_intensity = fmax(0, vector_dot(hitinfo->surface_dir, normalize(vector_subtract(data->light.light_point, hitinfo->pos))) * data->light.light_ratio);

	// diffuse color
	diffuse_color = vector_multiply(hitinfo->obj_color, diffuse_intensity);

	// final color
	final_color.x = (int)fmin(255.0, ambient_color.x + diffuse_color.x);
	final_color.y = (int)fmin(255.0, ambient_color.y + diffuse_color.y);
	final_color.z = (int)fmin(255.0, ambient_color.z + diffuse_color.z);
	if (is_lit)
		return ((int)final_color.x << 24 | (int)final_color.y << 16 | (int)final_color.z << 8 | 255);

	return ((int)ambient_color.x << 24 | (int)ambient_color.y << 16 | (int)ambient_color.z << 8 | 255);
}
