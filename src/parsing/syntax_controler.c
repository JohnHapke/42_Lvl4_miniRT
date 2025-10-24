/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_controler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 07:59:09 by johnhapke         #+#    #+#             */
/*   Updated: 2025/10/24 18:30:47 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	check_line(char *line)
{
	const size_t	len = ft_strlen(line);
	const char		*valid_formats[7] = {
		"A% %f% %i,%i,%i",
		"C% %f,%f,%f% %f,%f,%f% %i",
		"L% %f,%f,%f% %f% %i,%i,%i",
		"pl% %f,%f,%f% %f,%f,%f% %i,%i,%i",
		"cy% %f,%f,%f% %f,%f,%f% %f% %f% %i,%i,%i",
		"sp% %f,%f,%f% %f% %i,%i,%i",
		NULL
	};
	int	i;

	i = 0;
	if (len > 0 && line[len - 1] == '\n')
	    line[len - 1] = '\0';
	while (valid_formats[i])
	{
		if (match_format(valid_formats[i], line))
			return (true);
		i++;
	}
	return (false);
}

void ft_control_type_identifier(char *file, t_rt_data *data)
{
	int		fd;
	char	*line;
	int		a;
	int		c;
	int		l;

	a = 0;
	c = 0;
	l = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_parsing_error_handler(NULL, data);
	line = ft_get_next_line(fd);
	while (line)
	{
		if (line[0] != '#' && line[0] != '\n')
		{
			if (!check_line(line))
			{
				close(fd);
				ft_get_next_line(-1);
				ft_parsing_error_handler(line, data);
			}
			if (line[0] == 'A')
				a++;
			else if (line[0] == 'C')
				c++;
			else if (line[0] == 'L')
				l++;
		}
		free(line);
		line = ft_get_next_line(fd);
		if (!line)
			break ;
	}
	close(fd);
	ft_get_next_line(-1);
	if (a != 1 || c != 1 || l != 1)
		ft_parsing_error_handler(line, data);
}
