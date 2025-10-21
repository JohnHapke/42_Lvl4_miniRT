/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:29:28 by johnhapke         #+#    #+#             */
/*   Updated: 2025/10/21 22:07:03 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void ft_parsing_error_handler(char *line, t_rt_data *data)
{
	printf("Error: %s\n", line);
	ft_free_parsing(line, data);
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
}