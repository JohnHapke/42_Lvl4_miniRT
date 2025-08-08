/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:28:35 by iherman-          #+#    #+#             */
/*   Updated: 2024/12/15 18:00:33 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	ret;
	int	polarity;

	ret = 0;
	polarity = 0;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (*str == '-' && *(str + 1) >= '0' && *(str + 1) <= '9')
	{
		polarity++;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		ret = (ret * 10) + (*str - 48);
		str++;
	}
	if (polarity == 0)
		return (ret);
	else if (polarity == 1)
		return (-ret);
	return (0);
}
