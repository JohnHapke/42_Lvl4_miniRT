/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:13:04 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/22 14:58:41 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_rt_data	data;
	mlx_t		*mlx_win;

	(void) argc;
	ft_parsing_handler(argv[1], &data);
	mlx_win = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT", false);
	mlx_loop(mlx_win);
	ft_free_parsing(&data);
	return (0);
}
