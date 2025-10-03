/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:00:34 by johnhapke         #+#    #+#             */
/*   Updated: 2025/10/03 11:28:15 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// ToDo: ray from t to light has to be calculated to see if there is an object in between
/*
static bool	reaches_light(t_ray ray, t_rt_data *data)
{
	t_hitinfo	hitinfo;
	int			hit;
	t_hitinfo	best_hit;
	t_obj		*obj;

	obj = data->obj;
	best_hit.t = -1;
	while (obj != NULL)
	{
		hit = obj->fct_ptr(obj->obj, ray, &hitinfo);
		if (hit == 1 && (hitinfo.t > 0 && hitinfo.t < best_hit.t))
		{
			best_hit = hitinfo;
		}
		obj = obj->next;
	}

	return (false);
}*/

unsigned int	calculate_color(const t_hitinfo *hitinfo, t_rt_data *data)
{
	t_color	ambient_color;
	t_color	diffuse_color;
	double	diffuse_intensity;
	t_color	final_color;

	// ambient color
	ambient_color.R = hitinfo->obj_color.R * data->amb_light.light_ratio;
	ambient_color.G = hitinfo->obj_color.G * data->amb_light.light_ratio;
	ambient_color.B = hitinfo->obj_color.B * data->amb_light.light_ratio;

	// diffuse intensity
	diffuse_intensity = fmax(0, vector_dot(hitinfo->surface_dir, normalize(vector_subtract(data->light.light_point, hitinfo->pos))) * data->light.bright_ratio);

	// diffuse color
	diffuse_color.R = hitinfo->obj_color.R * diffuse_intensity;
	diffuse_color.G = hitinfo->obj_color.G * diffuse_intensity;
	diffuse_color.B = hitinfo->obj_color.B * diffuse_intensity;

	// final color
	final_color.R = (int)fmin(255.0, ambient_color.R + diffuse_color.R);
	final_color.G = (int)fmin(255.0, ambient_color.G + diffuse_color.G);
	final_color.B = (int)fmin(255.0, ambient_color.B + diffuse_color.B);
	return ((int)final_color.R << 24 | (int)final_color.G << 16 | (int)final_color.B << 8 | 255);
}
