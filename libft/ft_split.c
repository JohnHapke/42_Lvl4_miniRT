/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:23:12 by iherman-          #+#    #+#             */
/*   Updated: 2024/12/15 17:59:26 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		b;

	i = 0;
	count = 0;
	b = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && b == 0)
		{
			count++;
			b = 1;
		}
		else if (s[i] == c)
			b = 0;
		i++;
	}
	return (count);
}

static char	*cust_strcpy(char const *s, char c, size_t start)
{
	size_t		i;
	size_t		len;
	char		*ret;

	i = 0;
	len = 0;
	while (s[start + len] != c && s[start + len] != '\0')
		len++;
	ret = (char *) malloc((len + 1) * sizeof(char));
	if (ret == NULL)
	{
		return (NULL);
	}
	while (i < len)
	{
		ret[i] = s[i + start];
		i++;
	}
	ret[len] = '\0';
	return (ret);
}

static int	freeall(char **ret)
{
	size_t	i;

	i = 0;
	while (ret[i] != NULL)
	{
		free(ret[i]);
		i++;
	}
	free (ret);
	return (0);
}

static int	wcpy(char const *s, char c, char **ret)
{
	size_t	i;
	size_t	j;
	int		b;

	i = 0;
	j = 0;
	b = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && b == 0)
		{
			ret[j] = cust_strcpy(s, c, i);
			if (ret[j] == NULL)
				return (freeall(ret));
			b = 1;
			j++;
		}
		else if (s[i] == c)
			b = 0;
		i++;
	}
	ret[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;

	ret = (char **)malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	if (wcpy(s, c, ret) == 0)
		return (NULL);
	return (ret);
}
