/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:13:04 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/13 17:59:32 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	*t_func(mlx_t	*mlx_win)
{
	int	x = 0;
	int	y = 0;
	while (x < WINDOW_HEIGHT)
	{
		while(y < WINDOW_WIDTH)
		{
			mlx_put_pixel()
			y++;
		}
		x++;
	}
}

int	main(int argc, char *argv[])
{
	mlx_t	*mlx_win;

	(void) argc; (void) argv;

	mlx_win = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT", false);
	mlx_key_hook(mlx_win, &t_func, mlx_win);
	mlx_loop(mlx_win);
}
