/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:16:25 by iherman-          #+#    #+#             */
/*   Updated: 2024/12/15 17:56:24 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rev(char *s, size_t i)
{
	size_t		nll;
	size_t		j;
	char		buff;

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

static int	isspecial(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	else if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return (1);
	}
	else
		return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	i;
	int		p;
	char	s[12];

	i = 0;
	p = 0;
	if (isspecial(n, fd) != 0)
		return ;
	if (n < 0)
	{
		n = -n;
		p = 1;
	}
	while (n > 0)
	{
		s[i] = ((n % 10) + 48);
		n = n / 10;
		i++;
	}
	s[i] = '\0';
	rev(s, i);
	if (p == 1)
		write(fd, "-", 1);
	write(fd, s, i);
}
