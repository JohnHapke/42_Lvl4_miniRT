/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:04:04 by iherman-          #+#    #+#             */
/*   Updated: 2024/12/16 13:18:54 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*sub;

	i = 0;
	if (start >= ft_strlen(s))
		sub = ((char *)malloc(sizeof(char)));
	else if ((len + start) > ft_strlen(s))
		sub = (char *)malloc((((ft_strlen(s) - start) + 1) * sizeof(char)));
	else
		sub = (char *)malloc(((len + 1) * sizeof(char)));
	if (sub == NULL)
		return (NULL);
	while (i < len && start < ft_strlen(s))
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
