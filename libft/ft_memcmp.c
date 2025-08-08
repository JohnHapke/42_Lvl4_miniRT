/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:03:32 by iherman-          #+#    #+#             */
/*   Updated: 2024/12/15 18:00:02 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t num)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	if (num == 0)
		return (0);
	i = 0;
	c1 = (unsigned char *) p1;
	c2 = (unsigned char *) p2;
	while (i < num)
	{
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}
