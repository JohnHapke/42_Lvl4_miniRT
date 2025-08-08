/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:22:42 by iherman-          #+#    #+#             */
/*   Updated: 2024/12/16 12:27:21 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rev(char *s, int i)
{
	int		nll;
	int		j;
	char	buff;

	nll = i;
	j = 0;
	i--;
	while (j < i)
	{
		buff = s[i];
		s[i] = s[j];
		s[j] = buff;
		j++;
		i--;
	}
	s[nll] = '\0';
}

static int	count(int n)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	if (n < 0)
	{
		b = 1;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	if (b == 1)
		i++;
	return (i);
}

static char	*is_special(int n, char	*intmin)
{
	char	*ret;
	int		i;

	i = 0;
	if (n == 0)
	{
		ret = (char *)malloc((2 * sizeof(char)));
		if (ret == NULL)
			return (NULL);
		ret[0] = '0';
		ret[1] = '\0';
	}
	else
	{
		ret = (char *)malloc((12) * sizeof(char));
		if (ret == NULL)
			return (NULL);
		while (i < 12)
		{
			ret[i] = intmin[i];
			i++;
		}
		ret[12] = '\0';
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	int		i;
	int		polarity;
	char	*ret;

	i = 0;
	polarity = 0;
	if (n == 0 || n == -2147483648)
		return (is_special(n, "-2147483648"));
	ret = (char *)malloc(((count(n) + 1) * sizeof(char)));
	if (ret == NULL)
		return (NULL);
	if (n < 0)
	{
		polarity = 1;
		n = -n;
	}
	while (n > 0)
	{
		ret [i++] = n % 10 + 48;
		n = n / 10;
	}
	if (polarity == 1)
		ret[i++] = '-';
	rev(ret, i);
	return (ret);
}
