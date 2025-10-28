/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:43:39 by johnhapke         #+#    #+#             */
/*   Updated: 2025/10/28 10:21:54 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	ft_atof(const char *str)
{
	int		i;
	int		start;
	int		sign;
	double	res;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	while (str[i] != '.' && str[i] != '\0')
		i++;
	if (str[i] != '\0')
		i++;
	start = i;
	while (str[i] != '\0')
		i++;
	res = ft_atoi(&str[start]);
	res = (double)res / pow(10.0, i - start);
	res = (res * sign) + ft_atoi(str);
	return (res);
}

static double	ft_convert_to_atof(int start, int end,
	char *line, t_rt_data *data)
{
	char	*str;
	double	res;
	int		j;

	str = malloc((end - start + 1) * sizeof(char));
	if (!str)
		ft_parsing_error_handler((char *)line, "Internal: malloc failed", data);
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

double	ft_prepare_to_convert_atoi(char *line, int *i, t_rt_data *data)
{
	int		start;
	int		end;
	double	res;

	while (!ft_isdigit(line[*i]) && line[*i] != '-')
		(*i)++;
	start = *i;
	if (line[*i] == '-')
		(*i)++;
	while (ft_isdigit(line[*i]))
		(*i)++;
	end = *i;
	res = ft_convert_to_atof(start, end, line, data);
	return (res);
}

double	ft_prepare_to_convert_atof(char *line, int *i, t_rt_data *data)
{
	int		start;
	int		end;
	double	res;

	while (!ft_isdigit(line[*i]) && line[*i] != '-')
		(*i)++;
	start = *i;
	if (line[*i] == '-')
		(*i)++;
	while ((ft_isdigit(line[*i])))
		(*i)++;
	if (line[*i] == '.')
		(*i)++;
	while (ft_isdigit(line[*i]))
		(*i)++;
	end = *i;
	res = ft_convert_to_atof(start, end, line, data);
	return (res);
}
