/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:39:13 by iherman-          #+#    #+#             */
/*   Updated: 2025/11/04 12:40:50 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
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

static bool	format_error(const char **line)
{
	(void) line;
	return (false);
}

static bool (*check_identifier(char c))(const char **)
{
	if (c == ' ')
		return (&format_whitespace);
	else if (c == 'f')
		return (&format_float);
	else if (c == 'd' || c == 'i')
		return (&format_int);
	else
		return (&format_error);
}

bool	match_format(const char *restrict format, const char *line)
{
	bool (*format_check)(const char **);
	if (!format || !line)
		return (false);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			format_check = check_identifier(*format);
			if (!format_check(&line))
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
