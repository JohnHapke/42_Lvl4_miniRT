/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:37:22 by iherman-          #+#    #+#             */
/*   Updated: 2024/12/16 13:36:01 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (dest);
	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	if (cdest > csrc && cdest < csrc + n)
	{
		while (n-- > 0)
			cdest[n] = csrc[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	return (dest);
}
