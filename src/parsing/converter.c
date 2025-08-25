/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:43:39 by johnhapke         #+#    #+#             */
/*   Updated: 2025/08/25 11:42:05 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	ft_atof(const char *str)
{
	int		i;
	int		start;
	double	res;

	i = 0;
	res = 0;
	while (str[i] != '.' && str[i] != '\0')
		i++;
	if (str[i] != '\0')
		i++;
	start = i;
	while (str[i] != '\0' && str[start] != '\0')
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

static double ft_convert_to_atof(int start, int end, const char *line, t_rt_data *data)
{
	char	*str;
	double	res;
	int		j;

	str = malloc((end - start + 1) * sizeof(char));
	if (!str)
		ft_parsing_error_handler((char *)line, data);
	j = 0;
	while (start < end)
	{
		str[j++] = line[start++];
	}
	str[j] = '\0';
	res = ft_atof(str);
	free (str);
	return (res);
}

double	ft_prepare_to_convert_atoi(const char *line, int *i, t_rt_data *data)
{
	int		start;
	int		end;
	double	res;

	while (!ft_isdigit(line[*i]) && ft_strncmp(&line[*i], "-", 1) != 0)
		(*i)++;
	start = *i;
	if (ft_strncmp(&line[*i], "-", 1) == 0)
		(*i)++;
	while (ft_isdigit(line[*i]))
		(*i)++;
	end = *i;
	res = ft_convert_to_atof(start, end, line, data);
	return (res);
}

double	ft_prepare_to_convert_atof(const char *line, int *i, t_rt_data *data)
{
	int		start;
	int		end;
	double	res;

	while (!ft_isdigit(line[*i]) && ft_strncmp(&line[*i], "-", 1) != 0)
		(*i)++;
	start = *i;
	if (ft_strncmp(&line[*i], "-", 1) == 0)
		(*i)++;
	while ((ft_isdigit(line[*i]) || ft_strncmp(&line[*i], ".", 1) == 0) && ft_strncmp(&line[*i], ",", 1) != 0)
		(*i)++;
	end = *i;
	res = ft_convert_to_atof(start, end, line, data);
	return (res);
}
