/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_basic_arithmetic.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:47:04 by iherman-          #+#    #+#             */
/*   Updated: 2025/10/21 12:47:36 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

bool	vector_is_larger(t_vec3 larger, t_vec3 smaller)
{
	if (vector_dot(larger, larger) > vector_dot(smaller, smaller))
		return (true);
	return (false);
}