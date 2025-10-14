/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:00:34 by johnhapke         #+#    #+#             */
/*   Updated: 2025/10/11 15:51:05 by iherman-         ###   ########.fr       */
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

t_vec3 calculate_specular(const t_hitinfo *hitinfo, const t_rt_data *data, double shininess)
{
    t_vec3 L = normalize(vector_subtract(data->light.light_point, hitinfo->pos));
    t_vec3 V = normalize(vector_subtract(data->camera.viewpoint, hitinfo->pos));
    t_vec3 N = hitinfo->surface_dir;
    double NdotL = fmax(0, vector_dot(N, L));
    t_vec3 R = vector_subtract(vector_multiply(N, 2 * NdotL), L);
    double RdotV = fmax(0, vector_dot(R, V));
    double specular_intensity = pow(RdotV, shininess);
    return (vector_multiply((t_vec3){255, 255, 255}, specular_intensity));
}

unsigned int	calculate_color(const t_hitinfo *hitinfo, t_rt_data *data)
{
	t_vec3	ambient_color;
	t_vec3	diffuse_color;
	t_vec3	specular_color;
	t_vec3	final_color;
	double	diffuse_intensity;

	ambient_color = vector_multiply(hitinfo->obj_color, data->amb_light.light_ratio);
	if (reaches_light(hitinfo, data))
	{
		diffuse_intensity = fmax(0, vector_dot(hitinfo->surface_dir, normalize(vector_subtract(data->light.light_point, hitinfo->pos))) * data->light.light_ratio);
		diffuse_color = vector_multiply(hitinfo->obj_color, diffuse_intensity);
		specular_color = calculate_specular(hitinfo, data, SPECULAR_M);
		final_color.x = (int)fmin(255.0, ambient_color.x + diffuse_color.x + specular_color.x);
		final_color.y = (int)fmin(255.0, ambient_color.y + diffuse_color.y + specular_color.y);
		final_color.z = (int)fmin(255.0, ambient_color.z + diffuse_color.z + specular_color.z);
		return ((int)final_color.x << 24 | (int)final_color.y << 16 | (int)final_color.z << 8 | 255);
	}
	return ((int)ambient_color.x << 24 | (int)ambient_color.y << 16 | (int)ambient_color.z << 8 | 255);
}
