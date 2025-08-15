/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:46:29 by jhapke            #+#    #+#             */
/*   Updated: 2025/06/21 16:26:34 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_get_next_line(int fd);
char	*ft_line_extract(char *buffer);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_ft_save_remainder(char *buffer);
char	*ft_buffer(int fd, char *str);
char	*ft_strchr_gnl(char *str, int c);

#endif