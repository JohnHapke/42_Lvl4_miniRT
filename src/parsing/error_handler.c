/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:29:28 by johnhapke         #+#    #+#             */
/*   Updated: 2025/09/03 12:20:18 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void ft_parsing_error_handler(char *line, t_rt_data *data)
{
	ft_free_parsing(line, data);
	printf("Error\n");
	exit(1);
}

static void	free_lst(t_obj *obj)
{
	t_obj	*current;
	t_obj	*next;

	current = obj;
	while (current != NULL)
	{
		next = current->next;
		free(current->obj);
		free(current);
		current = next;
	}
}

void	ft_free_parsing(char *line, t_rt_data *data)
{
	ft_get_next_line(-1);
	if (line)
		free(line);
	if (data->obj)
		free_lst(data->obj);
	if (data)
		free(data);
}