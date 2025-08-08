/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:34:38 by iherman-          #+#    #+#             */
/*   Updated: 2024/12/16 16:29:36 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	char		*ret;

	i = 0;
	ret = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		ret[i] = s1[i];
		i++;
	}
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		ret[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
