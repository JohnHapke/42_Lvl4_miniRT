/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:43:39 by johnhapke         #+#    #+#             */
/*   Updated: 2025/10/21 22:00:00 by iherman-         ###   ########.fr       */
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

static double ft_convert_to_atof(int start, int end, char *line, t_rt_data *data)
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
	while ((ft_isdigit(line[*i]) || line[*i] == '.') && line[*i] != ',')
		(*i)++;
	end = *i;
	res = ft_convert_to_atof(start, end, line, data);
	return (res);
}

/*int	get_digit_count(char *s)
{
	int	i;

	i = 0;

	if (s[i] == '-')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	return (i);
}

double	ft_prepare_to_convert_atof(char *line, int *i, t_rt_data *data)
{
	double	res;
	int		signage;
	int		n;

	signage = 1;
	while (!ft_isdigit(line[*i]) && line[*i] != '-')
		(*i)++;
	if (line[*i] == '-')
	{
		(*i)++;
		signage = -1;
	}
	n = ft_atoi(line + *i);
	*i += get_digit_count(line + *i);
	res = (double) n;
	if (line[*i] != '.')
		return (res);
	else
		(*i)++;
	n = ft_atoi(line + *i);
	if (n < 0)
		ft_parsing_error_handler(line, data);
	res += (double)n / pow(10.0, get_digit_count(line + *i));
	*i += get_digit_count(line + *i);
	if (line[*i] == ',')
		(*i)++;
	res = res * signage;
	return (res);
}*/
