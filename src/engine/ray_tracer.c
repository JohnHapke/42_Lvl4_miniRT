/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:07:06 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/02 11:40:17 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned int	shoot_ray(t_rt_data *data, int screen_x, int screen_y)
{
	t_ray		ray;
	unsigned char	alpha;

	//ray = generate_ray();
	(void) data;
	ray.color.R = (unsigned char)((screen_x * 255) / (WINDOW_WIDTH - 1));
	ray.color.G = (unsigned char)((screen_y * 255) / (WINDOW_HEIGHT - 1));
	ray.color.B = 255;
	alpha = 255;
	return (ray.color.R << 24 | ray.color.G << 16 | ray.color.B << 8 | alpha);
}

void	raytracer(void *tmp_data)
{
	t_rt_data		*data;
	unsigned int	color;
	int				screen_x;
	int				screen_y;
	mlx_image_t		*img;

	data = (t_rt_data *)tmp_data;
	img	= mlx_new_image(data->mlx_win, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!img)
		return ;
	screen_x = 0;
	screen_y = 0;
	while (screen_x < WINDOW_WIDTH)
	{
		while (screen_y < WINDOW_HEIGHT)
		{
			color = shoot_ray(data, screen_x, screen_y);
			mlx_put_pixel(img, screen_x, screen_y, color);
			screen_y++;
		}
		screen_y = 0;
		screen_x++;
	}
	mlx_image_to_window(data->mlx_win, img, 0, 0);
	// memory leaks :D
}
