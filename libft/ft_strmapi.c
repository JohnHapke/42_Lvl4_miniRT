/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:59:03 by iherman-          #+#    #+#             */
/*   Updated: 2024/12/16 16:09:35 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	char		*ret;

	i = 0;
	ret = (char *) malloc(((ft_strlen(s) + 1) * sizeof(char)));
	if (ret == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		ret[i] = (*f)(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
