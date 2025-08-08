/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:03:33 by iherman-          #+#    #+#             */
/*   Updated: 2024/12/15 18:00:29 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t num)
{
	unsigned char	*mem;
	size_t			i;

	mem = (unsigned char *)s;
	i = 0;
	while (i < num)
	{
		mem[i] = '\0';
		i++;
	}
}
