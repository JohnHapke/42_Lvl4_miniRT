/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_controler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 07:59:09 by johnhapke         #+#    #+#             */
/*   Updated: 2025/11/04 12:37:49 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	check_line(char *line)
{
	size_t		len;
	int			i;
	const char	*valid_formats[7] = {"A% %f% %i,%i,%i",
		"C% %f,%f,%f% %f,%f,%f% %i",
		"L% %f,%f,%f% %f% %i,%i,%i",
		"pl% %f,%f,%f% %f,%f,%f% %i,%i,%i",
		"cy% %f,%f,%f% %f,%f,%f% %f% %f% %i,%i,%i",
		"sp% %f,%f,%f% %f% %i,%i,%i",
		NULL};

	len = ft_strlen(line);
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

static void	count_acl(char line, int *a, int *c, int *l)
{
	if (line == 'A')
		(*a)++;
	else if (line == 'C')
		(*c)++;
	else if (line == 'L')
		(*l)++;
}

char	handling_line_check(int fd, t_rt_data *data)
{
	char	*line;
	char	c;

	c = '\0';
	line = ft_get_next_line(fd);
	if (line[0] != '#' && line[0] != '\n')
	{
		if (!check_line(line))
		{
			close(fd);
			ft_get_next_line(-1);
			parsing_error_handler(line,
				"Usage: line does not conform to format", data);
		}
		c = line[0];
		free(line);
	}
	return (c);
}

void	control_type_identifier(char *file, t_rt_data *data)
{
	int		fd;
	int		a;
	int		c;
	int		l;
	char	var;

	var = '\0';
	a = 0;
	c = 0;
	l = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		parsing_error_handler(NULL, "Internal: failed to open file", data);
	while (1)
	{
		var = handling_line_check(fd, data);
		if (var == 0)
			break ;
		count_acl(var, &a, &c, &l);
	}
	close(fd);
	if (a != 1 || c != 1 || l != 1)
		parsing_error_handler(NULL,
			"Usage: can only have 1x A, C and L", data);
}
