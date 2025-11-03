/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:02:08 by iherman-          #+#    #+#             */
/*   Updated: 2025/11/03 11:04:15 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	intersect_plane(void *obj, t_ray ray, t_hitinfo *hit)
{
	const t_plane	*plane;
	double			denom;
	t_vec3			diff;

	plane = (t_plane *)obj;
	denom = vector_dot(ray.direction, plane->norm_vec);
	if (fabs(denom) < EPSILON)
		return (false);
	diff = vector_subtract(plane->pos, ray.origin);
	hit->t = vector_dot(diff, plane->norm_vec) / denom;
	if (hit->t < 0)
		return (false);
	hit->surface_dir = plane->norm_vec;
	if (vector_dot(ray.direction, hit->surface_dir) > 0)
		hit->surface_dir = vector_multiply(hit->surface_dir, -1);
	hit->obj_color = plane->color;
	hit->pos = vector_add(ray.origin, vector_multiply(ray.direction, hit->t));
	return (true);
}
