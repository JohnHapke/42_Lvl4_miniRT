/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:40:49 by johnhapke         #+#    #+#             */
/*   Updated: 2025/08/20 15:49:24 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	ft_control_input_atof(const char *str)
{
	int	i;
	int	point;

	point = 0;
	i = -1;
	if (!str)
		return (1);
	while (str[++i] != '\0')
	{
		if (!ft_isdigit(str[i]))
		{
			if (ft_strncmp(&str[i], ".", 1) != 0)
				return (1);
			else
				point++;
			continue;
		}
		else
			continue;
	}
	if (point > 1)
		return (1);
	return (0);
}

double	ft_atof(const char *str)
{
	int	i;
	int	start;
	double	res;

	if (ft_control_input_atof(str))
		ft_parsing_error_handler();
	i = 1;
	while (str[i] != '.')
		i++;
	i++;
	start = i;
	while (str[i] != '\0')
		i++;
	res = ft_atoi(&str[start]);
	while (start < i)
	{
		res /= 10;
		start++;
	}
	res = res + ft_atoi(str);
	return (res);
}
