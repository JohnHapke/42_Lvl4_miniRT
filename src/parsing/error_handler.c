/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:29:28 by johnhapke         #+#    #+#             */
/*   Updated: 2025/11/03 11:16:51 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parsing_error_handler(char *line, char *msg,
			t_rt_data *data)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	if (line)
	{
		ft_putstr_fd("Line: ", STDERR_FILENO);
		ft_putendl_fd(line, STDERR_FILENO);
	}
	free_parsing(line, data);
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

void	free_parsing(char *line, t_rt_data *data)
{
	ft_get_next_line(-1);
	if (line)
		free(line);
	if (data->obj)
		free_lst(data->obj);
}
