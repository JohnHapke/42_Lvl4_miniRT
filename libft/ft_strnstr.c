/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:37:56 by iherman-          #+#    #+#             */
/*   Updated: 2024/12/16 15:02:59 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		needleleng;

	i = 0;
	needleleng = 0;
	while (little[needleleng] != '\0')
		needleleng++;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && (i + needleleng) <= len)
	{
		if (ft_strncmp(&big[i], little, needleleng) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
