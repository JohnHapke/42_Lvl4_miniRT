/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_advanced.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:21:21 by iherman-          #+#    #+#             */
/*   Updated: 2025/10/28 16:12:54 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline double	vector_length(t_vec3 vec)
{
	return (sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z)));
}

inline t_vec3	normalize(t_vec3 vec)
{
	const double	v = vector_length(vec);
	t_vec3			normalized;

	if (v < EPSILON)
		return ((t_vec3){0.0, 0.0, 0.0});
	normalized.x = vec.x / v;
	normalized.y = vec.y / v;
	normalized.z = vec.z / v;
	return (normalized);
}

inline t_vec3	vector_cross(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	res;

	res.x = vec1.y * vec2.z - vec1.z * vec2.y;
	res.y = vec1.z * vec2.x - vec1.x * vec2.z;
	res.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (res);
}

inline double	vector_dot(t_vec3 vec1, t_vec3 vec2)
{
	return ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
}
