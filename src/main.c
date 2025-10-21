/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:13:04 by iherman-          #+#    #+#             */
/*   Updated: 2025/10/21 21:59:23 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_rt_data	data;

	if (argc != 2)
	{
		write(2, "Error: Usage: Must provide .rt scene", 36);
		return (1);
	}
	ft_bzero(&data, sizeof(t_rt_data));
	ft_parsing_handler(argv[1], &data);
	mlx_handler(&data);
	mlx_loop(data.mlx_win);
	ft_free_parsing(NULL, &data);
	return (0);
}
