/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:11:15 by johnhapke         #+#    #+#             */
/*   Updated: 2025/11/03 11:13:32 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	project(t_vec3 v, t_vec3 axis)
{
	return (vector_multiply(axis, vector_dot(v, axis)));
}

static bool	intersect_cyl_cap(const t_cylinder *cylinder,
	const double height, t_ray ray, t_hitinfo *hitinfo)
{
	t_plane	cap;
	t_vec3	v;
	double	radius;

	cap.pos = vector_add(cylinder->pos,
			vector_multiply(cylinder->norm_vec, height));
	cap.norm_vec = cylinder->norm_vec;
	cap.color = cylinder->color;
	if (intersect_plane(&cap, ray, hitinfo))
	{
		radius = cylinder->diameter / 2.0;
		v = vector_subtract(hitinfo->pos, cap.pos);
		if (vector_dot(v, v) > radius * radius)
			return (false);
		return (true);
	}
	return (false);
}

static bool	intersect_cyl_wall(const t_cylinder *cylinder,
	t_ray ray, t_hitinfo *cyl_surf)
{
	double	sqrt_disc;
	t_vec3	d_proj;
	t_vec3	oc_proj;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	t[2];
	t_vec3	hit_to_axis;
	double	proj_len;

	d_proj = vector_subtract(ray.direction, project(ray.direction,
				cylinder->norm_vec));
	oc_proj = vector_subtract(vector_subtract(ray.origin, cylinder->pos),
			project(vector_subtract(ray.origin, cylinder->pos),
				cylinder->norm_vec));
	a = vector_dot(d_proj, d_proj);
	b = 2.0 * vector_dot(d_proj, oc_proj);
	c = vector_dot(oc_proj, oc_proj)
		- (cylinder->diameter * 0.5) * (cylinder->diameter * 0.5);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0.0)
	{
		cyl_surf->t = INFINITY;
		return (false);
	}
	sqrt_disc = sqrt(discriminant);
	t[0] = (-b - sqrt_disc) / (2.0 * a);
	t[1] = (-b + sqrt_disc) / (2.0 * a);
	if (t[0] > 0.0 && t[1] > 0.0)
		cyl_surf->t = fmin(t[0], t[1]);
	else if (t[0] > 0.0)
		cyl_surf->t = t[0];
	else if (t[1] > 0.0)
		cyl_surf->t = t[1];
	else
		return (false);
	cyl_surf->pos = vector_add(ray.origin,
			vector_multiply(ray.direction, cyl_surf->t));
	hit_to_axis = vector_subtract(cyl_surf->pos, cylinder->pos);
	proj_len = vector_dot(hit_to_axis, cylinder->norm_vec);
	if (proj_len < 0.0 || proj_len > cylinder->height)
		return (false);
	cyl_surf->surface_dir = normalize(vector_subtract(hit_to_axis,
				project(hit_to_axis, cylinder->norm_vec)));
	if (vector_dot(cyl_surf->surface_dir, ray.direction) > 0)
		cyl_surf->surface_dir = vector_multiply(cyl_surf->surface_dir, -1.0);
	cyl_surf->obj_color = cylinder->color;
	return (true);
}

int	intersect_cylinder(void *obj, t_ray ray, t_hitinfo *hit)
{
	t_cylinder			*cylinder;
	t_hitinfo			wall;
	t_hitinfo			cap;
	t_hitinfo			cap2;

	cylinder = (t_cylinder *)obj;
	hit->t = INFINITY;
	if (intersect_cyl_wall(cylinder, ray, &wall) && wall.t < hit->t)
		*hit = wall;
	if (intersect_cyl_cap(cylinder, cylinder->height, ray, &cap)
		&& cap.t < hit->t)
		*hit = cap;
	if (intersect_cyl_cap(cylinder, 0, ray, &cap2) && cap2.t < hit->t)
		*hit = cap2;
	if (hit->t == INFINITY)
		return (false);
	return (true);
}
