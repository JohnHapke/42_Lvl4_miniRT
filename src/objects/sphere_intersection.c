/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:45:04 by johnhapke         #+#    #+#             */
/*   Updated: 2025/10/14 10:39:41 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double determine_t(double a, double b, double discriminant)
{
	const double sqrt_d = sqrt(discriminant);
	const double t1 = (-b - sqrt_d) / (2.0 * a);
	const double t2 = (-b + sqrt_d) / (2.0 * a);

	if (t1 > 0.0 && t2 > 0.0)
		return fmin(t1, t2);
	else if (t1 > 0.0)
		return t1;
	else if (t2 > 0.0)
		return t2;
	return -1;
}

int	intersect_sphere(void *obj, t_ray ray, t_hitinfo *hit)
{
	const t_sphere *sphere = (t_sphere *)obj;
	double	a;
	double	b;
	double	discriminant;
	t_vec3	oc;

	oc = vector_subtract(ray.origin, sphere->pos);
	a = vector_dot(ray.direction, ray.direction);
	b = 2 * vector_dot(oc, ray.direction);
	discriminant = b * b - 4 * a * (vector_dot(oc, oc) - (sphere->diameter * 0.5) * (sphere->diameter * 0.5));
	if (discriminant < 0)
		return (0);
	hit->t = determine_t(a, b, discriminant);
	if (hit->t == -1)
		return (0);
	hit->pos = vector_add(ray.origin, vector_multiply(ray.direction, hit->t));
	hit->surface_dir = vector_divide(vector_subtract(hit->pos, sphere->pos), (sphere->diameter / 2));
	hit->obj_color = sphere->color;
	return (1);
}
