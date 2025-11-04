/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:40:42 by johnhapke         #+#    #+#             */
/*   Updated: 2025/11/04 12:33:18 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	convert_vec3(char *line, int *i, t_rt_data *data)
{
	t_vec3	ret;

	ret.x = prepare_to_convert_atof(line, i, data);
	ret.y = prepare_to_convert_atof(line, i, data);
	ret.z = prepare_to_convert_atof(line, i, data);
	return (ret);
}

bool	in_range(t_vec3 vec, double rl, double ru)
{
	if (vec.x < rl || vec.x > ru)
		return (false);
	if (vec.y < rl || vec.y > ru)
		return (false);
	if (vec.z < rl || vec.z > ru)
		return (false);
	return (true);
}

bool	is_normalized(t_vec3 vec)
{
	if (fabs(vector_length(vec) - 1) < 1e-2)
		return (true);
	return (false);
}
