/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:13:04 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/02 11:34:14 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	temp_printvector(t_vec3 vec)
{
	printf("%.3f, %.3f, %.3f\n", vec.x, vec.y, vec.z);
}
// Temp print function for during development, after parsing is finished.
void	temp_print_parsing_data(t_rt_data *data)
{
	printf("Start of data printer:\n");

	printf("\tAmbient light:\n");
	printf("\t\tlight ratio: %.3f\n", data->amb_light.light_ratio);
	printf("\t\tcolor: %d, %d, %d\n",
		data->amb_light.color.R,
		data->amb_light.color.G,
		data->amb_light.color.B);

	printf("\tCamera:\n");
	printf("\t\tviewpoint: ");
	temp_printvector(data->camera.viewpoint);
	printf("\t\tnorm vec: ");
	temp_printvector(data->camera.norm_vec);
	printf("\t\tFOV: %.3f\n", data->camera.fov);

	printf("\tLight:\n");
	printf("\t\tlight point: ");
	temp_printvector(data->light.light_point);
	printf("\t\tbrightness ratio: %.3f\n", data->light.bright_ratio);
	printf("\t\tcolor: %d, %d, %d\n",
		data->light.color.R,
		data->light.color.G,
		data->light.color.B);


	// Will have to modify sphere, plane, cylinder to be proper, null terminated arrays (t_sphere **spheres)
	// Lists would work too
	if (data->sphere)
	{
		printf("\tSphere:\n");
		printf("\t\tposition: ");
		temp_printvector(data->sphere->pos);
		printf("\t\tdiameter: %.3f\n", data->sphere->diameter);
		printf("\t\tcolor: %d, %d, %d\n",
			data->sphere->color.R,
			data->sphere->color.G,
			data->sphere->color.B);
	}

	if (data->plane)
	{
		printf("\tPlane:\n");
		printf("\t\tposition: ");
		temp_printvector(data->plane->pos);
		printf("\t\tnormal vector: ");
		temp_printvector(data->plane->norm_vec);
		printf("\t\tcolor: %d, %d, %d\n",
			data->plane->color.R,
			data->plane->color.G,
			data->plane->color.B);
	}

	if (data->cylinder)
	{
		printf("\tCylinder:\n");
		printf("\t\tposition: ");
		temp_printvector(data->cylinder->pos);
		printf("\t\tnormal vector: ");
		temp_printvector(data->cylinder->norm_vec);
		printf("\t\tdiameter: %.3f\n", data->cylinder->diameter);
		printf("\t\theight: %.3f\n", data->cylinder->height);
		printf("\t\tcolor: %d, %d, %d\n",
			data->cylinder->color.R,
			data->cylinder->color.G,
			data->cylinder->color.B);
	}
}

int	main(int argc, char *argv[])
{
	t_rt_data	*data;

	data = (t_rt_data *)ft_calloc(1, sizeof(t_rt_data));
	if (!data)
		ft_parsing_error_handler(NULL, data);
	(void) argc;
	ft_parsing_handler(argv[1], data);
	data->mlx_win = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT", false);
	mlx_loop_hook(data->mlx_win, &raytracer, (void *)data);
	mlx_loop(data->mlx_win);
	mlx_terminate(data->mlx_win);
	temp_print_parsing_data(data);
	ft_free_parsing(NULL, data);
	return (0);
}
