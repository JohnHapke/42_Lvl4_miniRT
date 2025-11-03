/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:40:42 by johnhapke         #+#    #+#             */
/*   Updated: 2025/11/03 10:42:45 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_cylinder(t_cylinder *cylinder)
{
	printf("=== CYLINDER-NODE DATA ===\n");
	printf("Position: (%.2f, %.2f, %.2f)\n",
		cylinder->pos.x, cylinder->pos.y, cylinder->pos.z);
	printf("Normal Vector: (%.2f, %.2f, %.2f) ",
		cylinder->norm_vec.x, cylinder->norm_vec.y, cylinder->norm_vec.z);
	printf("Diameter: %.2f\n", cylinder->diameter);
	printf("Height: %.2f\n", cylinder->height);
	printf("Color: RGB(%f, %f, %f) ",
		cylinder->color.x, cylinder->color.y, cylinder->color.z);
	printf("=====================\n");
}

int	cylinder_addback(t_obj **obj, t_cylinder *node)
{
	t_obj	*current;
	t_obj	*new_node;

	new_node = malloc(sizeof(t_obj));
	if (!new_node)
		return (1);
	new_node->obj = node;
	new_node->check_intersection = intersect_cylinder;
	new_node->next = NULL;
	current = (*obj);
	if (!(*obj))
		(*obj) = new_node;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	print_cylinder(new_node->obj);
	return (0);
}

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
