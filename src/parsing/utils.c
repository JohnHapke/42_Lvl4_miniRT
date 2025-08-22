/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnhapke <johnhapke@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:40:49 by johnhapke         #+#    #+#             */
/*   Updated: 2025/08/22 15:39:43 by johnhapke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_export_and_convert_atoi(const char *line, int *i)
{
	int		j;
	int		start;
	int		end;
	char	*str;
	int		res;

	while (!ft_isdigit(line[*i]) && ft_strncmp(&line[*i], "-", 1) != 0)
		(*i)++;
	start = *i;
	if (ft_strncmp(&line[*i], "-", 1) == 0)
		(*i)++;
	while (ft_isdigit(line[*i]))
		(*i)++;
	end = *i;
	str = malloc((end - start + 1) * sizeof(char));
	if (!str)
		ft_parsing_error_handler(NULL);
	j = 0;
	while (start < end)
	{
		str[j++] = line[start++];
	}
	str[j] = '\0';
	res = ft_atoi(str);
	free (str);
	return (res);
}

double	ft_export_and_convert_atof(const char *line, int *i)
{
	int		j;
	int		start;
	int		end;
	char	*str;
	double	res;

	while (!ft_isdigit(line[*i]) && ft_strncmp(&line[*i], "-", 1) != 0)
		(*i)++;
	start = *i;
	if (ft_strncmp(&line[*i], "-", 1) == 0)
		(*i)++;
	while ((ft_isdigit(line[*i]) || ft_strncmp(&line[*i], ".", 1) == 0) && ft_strncmp(&line[*i], ",", 1) != 0)
		(*i)++;
	end = *i;
	str = malloc((end - start + 1) * sizeof(char));
	if (!str)
		ft_parsing_error_handler(NULL);
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

static int	ft_control_input_atof(const char *str)
{
	int	i;
	int	point;

	point = 0;
	i = -1;
	if (str[++i] == '-')
		i++;
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
	int		i;
	int		start;
	double	res;

	if (ft_control_input_atof(str))
		ft_parsing_error_handler(NULL);
	i = 0;
	while (str[i] != '.' && str[i] != '\0')
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
