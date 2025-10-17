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

/*bool	solve_quad(t_vec3 vec1, t_vec3 vec2, double diameter, double *t1, double *t2) // expand into a more general function later that can be used in sphere intersection aswel, as they´re very similar mathematical formulas
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
}*/

t_vec3	project(t_vec3 v, t_vec3 axis)
{
	return (vector_multiply(axis, vector_dot(v, axis)));
}

static void intersect_cap_top(const t_cylinder cylinder, t_ray ray, t_hitinfo *cap_top)
{
	t_vec3	cap_center;
	double	cross_check;

	cap_center = vector_add(cylinder.pos, vector_multiply(cylinder.norm_vec, (cylinder.height / 2)));
	cross_check = vector_dot(ray.direction, cylinder.norm_vec);
	if (fabs(cross_check) < EPSILON)
	{
		cap_top->t = INFINITY;
		return ;
	}
	cap_top->t = vector_dot(vector_subtract(cap_center, ray.origin), cylinder.norm_vec) / cross_check;
	if (fabs(cap_top->t) < EPSILON)
	{
		cap_top->t = INFINITY;
		return ;
	}
	/* generate whole hitinfo */
	/* control hit_pos with diameter/2 to check if the hit is really in the cap*/
}

static void intersect_cap_bottom(const t_cylinder cylinder, t_ray ray, t_hitinfo *cap_bottom)
{
	/* same as cap_top just for the check we need the negative height, so a general function could be used with a int or boolean to distinguish the hitinfo*/
}

static void generate_cyl_surf_hitinfo(const t_cylinder cylinder, t_ray ray, t_hitinfo *cyl_surf)
{
	double	sqrt_disc;
	const t_vec3		d_proj = vector_subtract(ray.direction, project(ray.direction, cylinder.norm_vec));
	const t_vec3		oc_proj = vector_subtract(vector_subtract(ray.origin, cylinder.pos), project(vector_subtract(ray.origin, cylinder.pos), cylinder.norm_vec));
	const double a = vector_dot(d_proj, d_proj);
	const double b = 2.0 * vector_dot(d_proj, oc_proj);
	const double c = vector_dot(oc_proj, oc_proj) - (cylinder.diameter/2) * (cylinder.diameter/2);
	const double discriminant = b * b - 4 * a * c;
	double t1;
	double t2;
	t_vec3 hit_to_axis;
	double	proj_len;

	if (discriminant < 0.0)
	{
		cyl_surf->t = INFINITY;
		return ;
	}
	sqrt_disc = sqrt(discriminant);
	t1 = (-b - sqrt_disc) / (2.0 * a);
	t2 = (-b + sqrt_disc) / (2.0 * a);
	if (t1 > 0.0 && t2 > 0.0)
		cyl_surf->t = fmin(t1, t2);
	else if (t1 > 0.0)
		cyl_surf->t = t1;
	else
		cyl_surf->t = t2;
	cyl_surf->pos = vector_add(ray.origin, vector_multiply(ray.direction, cyl_surf->t));
	hit_to_axis = vector_subtract(cyl_surf->pos, cylinder.pos);
	proj_len = vector_dot(hit_to_axis, cylinder.norm_vec);
	if (proj_len < 0.0 || proj_len > cylinder.height)
		return (false);
	cyl_surf->surface_dir = normalize(vector_subtract(hit_to_axis, project(hit_to_axis, cylinder.norm_vec)));
	if (vector_dot(cyl_surf->surface_dir, ray.direction) > 0)
		cyl_surf->surface_dir = vector_multiply(cyl_surf->surface_dir, -1.0);
	cyl_surf->obj_color = cylinder.color;
}

static int	determine_best_t(const t_cylinder cylinder, t_ray ray, t_hitinfo *hit)
{
	t_hitinfo	cyl_surf;
	t_hitinfo	cap_top;
	t_hitinfo	cap_bottom;

	generate_cyl_surf_hitinfo(cylinder, ray, &cyl_surf);
	generate_cap_top_hitinfo(cylinder, ray, &cap_top);
	generate_cap_bottom_hitinfo(cylinder, ray, &cap_bottom);
	if (cyl_surf.t == -1 && cap_top.t == -1 && cap_bottom.t == -1)
		return (0);
	hit->t = INFINITY;
	if (cyl_surf.t > EPSILON && cyl_surf.t < hit->t)
		*hit = cyl_surf;
	if (cap_top.t > EPSILON && cap_top.t < hit->t)
		*hit = cap_top;
	if (cap_bottom.t > EPSILON && cap_bottom.t < hit->t)
		*hit = cap_bottom;
	return (1);
}

int	intersect_cylinder(void *obj, t_ray ray, t_hitinfo *hit)
{
	/*double	t1;
	double	t2;
	double	proj_len;
	const t_vec3		d_proj = vector_subtract(ray.direction, project(ray.direction, cylinder->norm_vec));
	const t_vec3		oc_proj = vector_subtract(vector_subtract(ray.origin, cylinder->pos), project(vector_subtract(ray.origin, cylinder->pos), cylinder->norm_vec));
	t_vec3 hit_to_axis;*/
	const t_cylinder	*cylinder = (t_cylinder *)obj;

	determine_best_t(cylinder, ray, hit);
	/*if (!solve_quad(d_proj, oc_proj, cylinder->diameter * 0.5, &t1, &t2))
		return (false);
	hit->t = INFINITY;
	if (t1 > EPSILON && t1 < hit->t)
		hit->t = t1;
	if (t2 > EPSILON && t2 < hit->t)
		hit->t = t2;

	double t_cap_top = intersect_cap_top(cylinder, ray);
	if (t_cap_top > EPSILON && t_cap_top < hit->t)
		hit->t = t_cap_top;
	double t_cap_bottom = intersect_cap_bottom(cylinder, ray);
	if (t_cap_bottom > EPSILON && t_cap_bottom < hit->t)
		hit->t = t_cap_bottom;
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
	return (true);*/
}
