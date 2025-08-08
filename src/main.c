/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:13:04 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/08 16:21:48 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	main(int argc, char *argv[])
{
	mlx_t	*mlx_win;

	(void) argc; (void) argv;

	mlx_win = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT", false);
	mlx_loop(mlx_win);
}