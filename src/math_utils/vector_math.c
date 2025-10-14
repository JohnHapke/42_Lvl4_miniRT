/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:21:21 by iherman-          #+#    #+#             */
/*   Updated: 2025/10/14 11:29:04 by iherman-         ###   ########.fr       */
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

t_vec3	vector_add(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	res;

	res.x = vec1.x + vec2.x;
	res.y = vec1.y + vec2.y;
	res.z = vec1.z + vec2.z;
	return (res);
}

t_vec3	vector_subtract(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	res;

	res.x = vec1.x - vec2.x;
	res.y = vec1.y - vec2.y;
	res.z = vec1.z - vec2.z;
	return (res);
}

t_vec3	vector_multiply(t_vec3 vec, const double factor)
{
	t_vec3	res;

	res.x = vec.x * factor;
	res.y = vec.y * factor;
	res.z = vec.z * factor;
	return (res);
}

t_vec3	vector_divide(t_vec3 vec, const double factor)
{
	t_vec3	res;

	res.x = vec.x / factor;
	res.y = vec.y / factor;
	res.z = vec.z / factor;
	return (res);
}

// returns true if first argument vector is larger
bool	vector_is_larger(t_vec3 larger, t_vec3 smaller)
{
	if (vector_length_squared(larger) > vector_length_squared(smaller))
		return (true);
	return (false);
}

t_vec3	vector_cross(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	res;

	res.x = vec1.y * vec2.z - vec1.z * vec2.y;
	res.y = vec1.z * vec2.x - vec1.x * vec2.z;
	res.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (res);
}

double	vector_dot(t_vec3 vec1, t_vec3 vec2)
{
	return ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
}
