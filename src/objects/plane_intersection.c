/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:02:08 by iherman-          #+#    #+#             */
/*   Updated: 2025/10/02 13:41:35 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	intersect_plane(void *obj, t_ray ray, t_hitinfo *hit)
{
	ft_bzero(hit, sizeof(t_hitinfo));
	hit->t = -1;
	(void) obj;
	(void) ray;
	return (0);
	/*t_plane	*plane;

	plane = (t_plane*) obj;
	hit->pos = vector_add(ray.origin, vector_multiply(ray.direction, hit->t));
	//hit->surface_dir = // tbd
	hit->obj = plane;
	hit->obj_type = PLANE;
	hit->obj_color = plane->color;*/
}
