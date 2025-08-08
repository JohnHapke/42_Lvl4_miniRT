/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:02:06 by iherman-          #+#    #+#             */
/*   Updated: 2024/12/16 13:21:27 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)malloc((num * size));
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (num * size));
	return (ptr);
}
