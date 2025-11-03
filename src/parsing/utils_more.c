/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:36:02 by johnhapke         #+#    #+#             */
/*   Updated: 2025/11/03 10:42:27 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_sphere(t_sphere *sphere)
{
	printf("=== SPHERE-NODE DATA ===\n");
	printf("Position: (%.2f, %.2f, %.2f)\n",
		sphere->pos.x, sphere->pos.y, sphere->pos.z);
	printf("Diameter: %.2f\n", sphere->diameter);
	printf("Color: RGB(%f, %f, %f) ",
		sphere->color.x, sphere->color.y, sphere->color.z);
	printf("===================\n");
}

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
	print_sphere(new_node->obj);
	return (0);
}

static void	print_plane(t_plane *plane)
{
	printf("=== PLANE-NODE DATA ===\n");
	printf("Position: (%.2f, %.2f, %.2f)\n",
		plane->pos.x, plane->pos.y, plane->pos.z);
	printf("Normal Vector: (%.2f, %.2f, %.2f)\n",
		plane->norm_vec.x, plane->norm_vec.y, plane->norm_vec.z);
	printf("Color: RGB(%f, %f, %f)\n",
		plane->color.x, plane->color.y, plane->color.z);
	printf("==================\n");
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
	print_plane(new_node->obj);
	return (0);
}
