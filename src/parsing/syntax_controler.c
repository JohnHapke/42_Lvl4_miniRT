/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_controler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 07:59:09 by johnhapke         #+#    #+#             */
/*   Updated: 2025/10/03 11:27:00 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int ft_control_digits(char *line)
{
	int	i;

	i = 0;
	while (ft_isalpha(line[i]) == 1 && line[i] != '\0')
		i++;
	while (line[i] != '\0')
	{
		if (ft_isalpha(line[i]) == 1)
			return (1);
		else if (line[i] == '.' && !(ft_isdigit(line[i - 1]) && ft_isdigit(line[i + 1])))
			return (1);
		else if (ft_isdigit(line[i]) && (!ft_isdigit(line[i + 1]) && line[i + 1] != '.'
			&& line[i + 1] != ',' && line[i + 1] != '\0' && line[i + 1] != ' ' && line[i + 1] != '\n'))
			return (1);
		else if (line[i] == ',' && !(ft_isdigit(line[i + 1]) || line[i + 1] == '-'))
			return (1);
		i++;
	}
	return (0);
}

void ft_control_type_identifier(char *file, t_rt_data *data)
{
	int		fd;
	char	*line;
	int		A;
	int		C;
	int		L;

	A = 0;
	C = 0;
	L = 0;
	fd = open(file, O_RDONLY);
	if (!fd)
		ft_parsing_error_handler(NULL, data);
	line = ft_get_next_line(fd);
	if (!line)
		ft_parsing_error_handler(line, data);
	while (line)
	{
		if (!ft_isalpha(line[0]) && ft_strncmp(line, "\n", 1) != 0)
			ft_parsing_error_handler(line, data);
		else if (ft_strncmp(line, "A ", 2) == 0)
			A++;
		else if (ft_strncmp(line, "C ", 2) == 0)
			C++;
		else if (ft_strncmp(line, "L ", 2) == 0)
			L++;
		else if (ft_strncmp(line, "sp ", 3) != 0 && ft_strncmp(line, "pl ", 3) != 0
			&& ft_strncmp(line, "cy ", 3) != 0 && ft_strncmp(line, "\n", 1) != 0)
			ft_parsing_error_handler(line, data);
		if (ft_control_digits(line) == 1)
			ft_parsing_error_handler(line, data);
		free(line);
		line = ft_get_next_line(fd);
		if (!line)
			break ;
	}
	close(fd);
	ft_get_next_line(-1);
	if (A > 1 || C > 1 || L > 1)
		ft_parsing_error_handler(line, data);
}
