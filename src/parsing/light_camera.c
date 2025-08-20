/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:03:21 by johnhapke         #+#    #+#             */
/*   Updated: 2025/08/20 16:05:39 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_export_and_convert(const char *line, int *i)
{
	int	j;
	int	start;
	int	end;
	char	*str;
	double	res;

	while (!ft_isdigit(line[*i]))
		(*i)++;
	start = *i;
	while (ft_isdigit(line[*i]) || ft_strncmp(&line[*i], ".", 1) == 0)
		(*i)++;
	end = *i;
	str = malloc((end - start + 1) * sizeof(char));
	if (!str)
		ft_parsing_error_handler();
	j = 0;
	while (start < end)
	{
		str[j++] = line[start++];
	}
	str[j] = '\0';
	res = ft_atof(str);
	free (str);
	printf("line[%d]\n", *i);
	return (res);
}

void	ft_parse_ambient_lighting(char *line, t_rt_data *data)
{
	printf("ambient light\n");
	int	i;

	i = 0;
	data->amb_light.light_ratio = ft_export_and_convert(line, &i);
	printf("%f\n", data->amb_light.light_ratio);
}

void	ft_parse_camera(char *line, t_rt_data *data)
{
	(void) line; (void) data;
	printf("camera\n");
}

void	ft_parse_light(char *line, t_rt_data *data)
{
	(void) line; (void) data;
	printf("light\n");
}
