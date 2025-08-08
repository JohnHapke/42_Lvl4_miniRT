/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:19:43 by iherman-          #+#    #+#             */
/*   Updated: 2024/12/16 13:03:10 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*haystack = (const unsigned char *)s;

	while (n-- > 0)
	{
		if (*haystack == (unsigned char)c)
			return ((void *)haystack);
		haystack++;
	}
	return (NULL);
}
