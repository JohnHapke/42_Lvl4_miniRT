/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:42:09 by iherman-          #+#    #+#             */
/*   Updated: 2024/12/16 13:08:32 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *source, size_t size)
{
	size_t	i;
	size_t	i2;
	size_t	ret;

	ret = (ft_strlen(dest) + ft_strlen(source));
	if (size <= ft_strlen(dest))
		return (ft_strlen(source) + size);
	i = ft_strlen(dest);
	i2 = 0;
	while (source[i2] != '\0' && i < (size - 1))
	{
		dest[i] = source[i2];
		i++;
		i2++;
	}
	dest[i] = '\0';
	return (ret);
}
