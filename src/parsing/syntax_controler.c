/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_controler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 07:59:09 by johnhapke         #+#    #+#             */
/*   Updated: 2025/11/04 13:46:02 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	check_line(char *line)
{
	const size_t	len = strlen(line);
	const char		*valid_formats[7] = {
		"A% %f% %i,%i,%i",
		"C% %f,%f,%f% %f,%f,%f% %i",
		"L% %f,%f,%f% %f% %i,%i,%i",
		"pl% %f,%f,%f% %f,%f,%f% %i,%i,%i",
		"cy% %f,%f,%f% %f,%f,%f% %f% %f% %i,%i,%i",
		"sp% %f,%f,%f% %f% %i,%i,%i",
		NULL
	};
	int				i;

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

static void	process_line(char *line, int *acl, t_rt_data *data)
{
	if (line[0] == '#' || line[0] == '\n')
		return ;
	if (!check_line(line))
		parsing_error_handler(line,
			"Usage: line does not conform to format", data);
	if (line[0] == 'A')
		acl[0]++;
	else if (line[0] == 'C')
		acl[1]++;
	else if (line[0] == 'L')
		acl[2]++;
}

void	control_type_identifier(char *file, t_rt_data *data)
{
	char	*line;
	int		fd;
	int		acl[3];

	ft_bzero(acl, sizeof(int) * 3);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		parsing_error_handler(NULL, "Internal: failed to open file", data);
	line = ft_get_next_line(fd);
	while (line)
	{
		process_line(line, acl, data);
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
	ft_get_next_line(-1);
	if (acl[0] != 1 || acl[1] != 1 || acl[2] != 1)
		parsing_error_handler(NULL, "Usage: can only have 1x A, C and L", data);
}
