/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:33:09 by iherman-          #+#    #+#             */
/*   Updated: 2024/12/15 17:59:54 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t num)
{
	unsigned char	*mem;
	size_t			i;

	i = 0;
	mem = (unsigned char *)s;
	while (i < num)
	{
		mem[i] = (unsigned char)c;
		i++;
	}
	return (mem);
}
