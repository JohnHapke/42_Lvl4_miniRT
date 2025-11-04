/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:36:02 by johnhapke         #+#    #+#             */
/*   Updated: 2025/11/04 12:33:52 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	sphere_addback(t_obj **obj, t_sphere *node)
{
	t_obj	*current;
	t_obj	*new_node;

	new_node = malloc(sizeof(t_obj));
	if (!new_node)
		return (1);
	new_node->obj = node;
	new_node->check_intersection = intersect_sphere;
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
	return (0);
}

int	plane_addback(t_obj **obj, t_plane *node)
{
	t_obj	*new_node;
	t_obj	*current;

	new_node = malloc(sizeof(t_obj));
	if (!new_node)
		return (1);
	new_node->obj = node;
	new_node->check_intersection = intersect_plane;
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
	return (0);
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
	return (0);
}
