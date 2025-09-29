/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:45:04 by johnhapke         #+#    #+#             */
/*   Updated: 2025/09/29 08:40:06 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double determine_t(double a, double b, double discriminat)
{
	double t1;
	double t2;

	printf("t calculation \n");
	t1 = (-b - sqrt(discriminat)) / (2 * a);
	t2 = (-b + sqrt(discriminat)) / (2 * a);
	printf("t1:%f, t2:%f \n", t1, t2);
	if (t1 > 0.001 && t2 > 0.001)
		return (t1);
	else if (t2 > 0.001)
		return (t2);
	return (-1);
}

int	intersect_sphere(void *obj, t_ray ray, t_hitinfo *hit)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	t_vec3	oc;

	t_sphere *sphere = (t_sphere *)obj;
	oc = vector_subtract(ray.origin, sphere->pos);
	a = vector_dot(ray.direction, ray.direction);
	b = 2 * vector_dot(oc, ray.direction);
	c = vector_dot(oc, oc) - (sphere->diameter/2) * (sphere->diameter/2);
	printf("a= %f, b=%f,c=%f \n", a, b, c);
	discriminant = b * b - 4 * a * c;
	printf("discrimant=%f\n", discriminant);
	if (discriminant < 0)
	{
		printf("discriminant < 0\n");
		return (0);
	}
	hit->t = determine_t(a, b, discriminant);
	printf("intersect_sphere best hit->t= %f, ", hit->t);
	if (hit->t == -1)
		return (0);
	hit->pos = vector_add(ray.origin, vector_multiply(ray.direction, hit->t));
	hit->surface_dir = vector_divide(vector_subtract(hit->pos, sphere->pos), (sphere->diameter / 2));
	hit->obj = sphere;
	hit->obj_type = SPHERE;
	return (1);
}
