/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:08:50 by iherman-          #+#    #+#             */
/*   Updated: 2025/02/15 16:12:49 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		len;

	temp = lst;
	len = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}
