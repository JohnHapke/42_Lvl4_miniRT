/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:28:02 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/08 16:17:36 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# include "../MLX42/include/MLX42/MLX42.h"

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 528
# endif // WINDOW_HEIGHT

# ifndef WINDOWN_WIDTH
#  define WINDOW_WIDTH 1048
# endif // WINDOW_WIDTH

/*
	To get normalized vector (for direction)
		Get the magnitude: √(x² + y² + z²) = magnitude
		Divide all components by magnitude: x/magnitude, y/magnitude, z/magnitude
*/

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

#endif // MINIRT_H
