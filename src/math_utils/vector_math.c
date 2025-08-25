/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:21:21 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/25 18:45:08 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vector_length(t_vec3 vec)
{
	return (sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z)));
}

// Good for length comparison and much cheaper on cpu. Use this if you dont need the exact length
double	vector_length_squared(t_vec3 vec)
{
	return (vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z);
}

t_vec3	normalize(t_vec3 vec)
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
