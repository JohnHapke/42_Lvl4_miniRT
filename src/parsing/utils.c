/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:22:54 by johnhapke         #+#    #+#             */
/*   Updated: 2025/09/03 12:43:27 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_sphere(t_sphere *sphere)
{
	printf("=== SPHERE-NODE DATA ===\n");
	printf("Position: (%.2f, %.2f, %.2f)\n", 
       sphere->pos.x, sphere->pos.y, sphere->pos.z);
	printf("Diameter: %.2f\n", sphere->diameter);
	printf("Color: RGB(%d, %d, %d) ", 
       sphere->color.R, sphere->color.G, sphere->color.B);
	printf("(Valid: %s)\n", 
       ((sphere->color.R >= 0 && sphere->color.R <= 255) &&
        (sphere->color.G >= 0 && sphere->color.G <= 255) &&
        (sphere->color.B >= 0 && sphere->color.B <= 255)) ? "YES" : "NO");
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
	new_node->next = NULL;
	new_node->type = SPHERE;
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
	printf("Color: RGB(%d, %d, %d)\n", 
       plane->color.R, plane->color.G, plane->color.B);
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
	new_node->next = NULL;
	new_node->type = PLANE;
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

static void	print_cylinder(t_cylinder *cylinder)
{
	printf("=== CYLINDER-NODE DATA ===\n");
	printf("Position: (%.2f, %.2f, %.2f)\n", 
       cylinder->pos.x, cylinder->pos.y, cylinder->pos.z);
	printf("Normal Vector: (%.2f, %.2f, %.2f) ", 
       cylinder->norm_vec.x, cylinder->norm_vec.y, cylinder->norm_vec.z);
	printf("(Valid: %s)\n", 
       ((cylinder->norm_vec.x >= 0 && cylinder->norm_vec.x <= 1) &&
        (cylinder->norm_vec.y >= 0 && cylinder->norm_vec.y <= 1) &&
        (cylinder->norm_vec.z >= 0 && cylinder->norm_vec.z <= 1)) ? "YES" : "NO");
	printf("Diameter: %.2f\n", cylinder->diameter);
	printf("Height: %.2f\n", cylinder->height);
	printf("Color: RGB(%d, %d, %d) ", 
       cylinder->color.R, cylinder->color.G, cylinder->color.B);
	printf("(Valid: %s)\n", 
       ((cylinder->color.R >= 0 && cylinder->color.R <= 255) &&
        (cylinder->color.G >= 0 && cylinder->color.G <= 255) &&
        (cylinder->color.B >= 0 && cylinder->color.B <= 255)) ? "YES" : "NO");
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
	new_node->next = NULL;
	new_node->type = CYLINDER;
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
