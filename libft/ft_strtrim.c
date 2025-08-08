/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:21:48 by iherman-          #+#    #+#             */
/*   Updated: 2024/12/16 14:58:11 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	find_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (isset(s1[i], set) == 0)
			break ;
		i++;
	}
	return (i);
}

static size_t	find_end(char const *s1, char const *set, int i)
{
	int	j;

	j = ft_strlen(s1);
	while (j > i && isset(s1[j - 1], set) != 0)
		j--;
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	size_t			j;
	char			*ret;

	i = find_start(s1, set);
	j = find_end(s1, set, i);
	if (i > ft_strlen(s1))
		return (ft_calloc(1, 1));
	else if (i > j)
		return (ft_calloc(1, 1));
	else
		ret = ft_substr(s1, i, (j - i));
	if (ret == NULL)
		return (NULL);
	return (ret);
}
