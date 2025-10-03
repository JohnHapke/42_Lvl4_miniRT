/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:49:47 by iherman-          #+#    #+#             */
/*   Updated: 2025/10/02 15:00:06 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	intersect_cylinder(void *obj, t_ray ray, t_hitinfo *hit)
{
	ft_bzero(hit, sizeof(t_hitinfo));
	hit->t = -1;
	(void) ray;
	(void) obj;
	return (0);

	t_cylinder	*cylinder;

	cylinder = (t_cylinder*) obj;
	hit->pos = vector_add(ray.origin, vector_multiply(ray.direction, hit->t));
	//hit->surface_dir = // tbd
	hit->obj = cylinder;
	hit->obj_type = CYLINDER;
	hit->obj_color = cylinder->color;
	return (0);
}
