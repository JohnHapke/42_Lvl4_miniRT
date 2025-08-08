/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:49:03 by iherman-          #+#    #+#             */
/*   Updated: 2025/02/15 19:33:19 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp;
	t_list	*old_list;
	void	*content;

	if (lst == NULL)
		return (NULL);
	old_list = lst;
	new_list = NULL;
	while (old_list != NULL)
	{
		content = f(old_list->content);
		temp = ft_lstnew(content);
		if (!temp)
		{
			free(content);
			ft_lstclear (&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, temp);
		old_list = old_list->next;
	}
	return (new_list);
}
