/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:02:08 by iherman-          #+#    #+#             */
/*   Updated: 2025/10/08 13:58:48 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	intersect_plane(void *obj, t_ray ray, t_hitinfo *hit)
{
	const t_plane	*plane = (t_plane *)obj;
	const double	denom = vector_dot(ray.direction, plane->norm_vec);
	t_vec3		diff;

	if (fabs(denom) < EPSILON)
		return (false);
	diff = vector_subtract(plane->pos, ray.origin);
	hit->t = vector_dot(diff, plane->norm_vec) / denom;
	hit->surface_dir = plane->norm_vec;
	if (vector_dot(ray.direction, hit->surface_dir) > 0)
	    hit->surface_dir = vector_multiply(hit->surface_dir, -1);
	hit->obj_color = plane->color;
	hit->pos = vector_add(ray.origin, vector_multiply(ray.direction, hit->t));
	if (hit->t < 0)
		return (false);
	return (true);
}
