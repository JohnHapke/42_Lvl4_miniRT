/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinderinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:49:47 by iherman-          #+#    #+#             */
/*   Updated: 2025/10/14 09:42:07 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	solve_quad(t_vec3 vec1, t_vec3 vec2, double diameter, double *t1, double *t2) // expand into a more general function later that can be used in sphere intersection aswel, as they´re very similar mathematical formulas
{
	double	sqrt_disc;
	const double a = vector_dot(vec1, vec1);
	const double b = 2.0 * vector_dot(vec1, vec2);
	const double c = vector_dot(vec2, vec2) - diameter * diameter;
	const double discriminant = b * b - 4 * a * c;

	if (discriminant < 0.0)
		return (false);
	sqrt_disc = sqrt(discriminant);
	*t1 = (-b - sqrt_disc) / (2.0 * a);
	*t2 = (-b + sqrt_disc) / (2.0 * a);
	return (true);
}

t_vec3	project(t_vec3 v, t_vec3 axis)
{
	return (vector_multiply(axis, vector_dot(v, axis)));
}

int	intersect_cylinder(void *obj, t_ray ray, t_hitinfo *hit)
{
	double	t1;
	double	t2;
	double	proj_len;
	const t_cylinder	*cylinder = (t_cylinder *)obj;
	const t_vec3		d_proj = vector_subtract(ray.direction, project(ray.direction, cylinder->norm_vec));
	const t_vec3		oc_proj = vector_subtract(vector_subtract(ray.origin, cylinder->pos), project(vector_subtract(ray.origin, cylinder->pos), cylinder->norm_vec));
	t_vec3 hit_to_axis;

	if (!solve_quad(d_proj, oc_proj, cylinder->diameter * 0.5, &t1, &t2))
		return (false);
	hit->t = INFINITY;
	if (t1 > EPSILON && t1 < hit->t)
		hit->t = t1;
	if (t2 > EPSILON && t2 < hit->t)
		hit->t = t2;
	if (hit->t == INFINITY)
		return (false);
	hit->pos = vector_add(ray.origin, vector_multiply(ray.direction, hit->t));
	hit_to_axis = vector_subtract(hit->pos, cylinder->pos);
	proj_len = vector_dot(hit_to_axis, cylinder->norm_vec);
	if (proj_len < 0.0 || proj_len > cylinder->height)
		return (false);
	hit->surface_dir = normalize(vector_subtract(hit_to_axis, project(hit_to_axis, cylinder->norm_vec)));
	if (vector_dot(hit->surface_dir, ray.direction) > 0)
		hit->surface_dir = vector_multiply(hit->surface_dir, -1.0);
	hit->obj_color = cylinder->color;
	return (true);
}
