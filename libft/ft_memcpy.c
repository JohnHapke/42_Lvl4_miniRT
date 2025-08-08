/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:14:11 by iherman-          #+#    #+#             */
/*   Updated: 2024/12/16 13:31:20 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*a;
	const unsigned char	*b;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (dest);
	a = (unsigned char *)dest;
	b = (const unsigned char *)src;
	i = 0;
	if (n == 0)
		return (dest);
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (dest);
}
