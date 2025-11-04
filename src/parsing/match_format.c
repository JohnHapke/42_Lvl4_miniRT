/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:39:13 by iherman-          #+#    #+#             */
/*   Updated: 2025/11/04 13:57:55 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static bool	format_whitespace(const char **line)
{
	if (**line != ' ')
		return (false);
	while (**line == ' ')
		(*line)++;
	return (true);
}

static bool	format_float(const char **line)
{
	int		decimal_found;
	bool	digit_found;

	decimal_found = 0;
	digit_found = false;
	if (**line == '-' || **line == '+')
		(*line)++;
	while (**line && (**line == '.' || ft_isdigit((unsigned char)**line)))
	{
		if (**line == '.')
			decimal_found++;
		if (ft_isdigit(**line))
			digit_found = true;
		(*line)++;
	}
	if (decimal_found > 1 || !digit_found)
		return (false);
	return (true);
}

static bool	format_int(const char **line)
{
	int		digit_found;

	digit_found = 0;
	if (**line == '-' || **line == '+')
		(*line)++;
	while (**line && ft_isdigit((unsigned char)**line))
	{
		(*line)++;
		digit_found++;
	}
	if (!digit_found)
		return (false);
	return (true);
}

static bool	check_identifier(const char c, const char **line)
{
	if (c == ' ')
		return (format_whitespace(line));
	else if (c == 'f')
		return (format_float(line));
	else if (c == 'd' || c == 'i')
		return (format_int(line));
	else
		return (false);
}

bool	match_format(const char *restrict format, const char *line)
{
	if (!format || !line)
		return (false);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!check_identifier(*format, &line))
				return (false);
			format++;
		}
		else if (*format != *line)
			return (false);
		else
		{
			format++;
			line++;
		}
	}
	return (true);
}
