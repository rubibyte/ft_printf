/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:00:23 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/09/29 21:03:06 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_node;
	t_list	*temp_next;

	if (!(*lst))
		return ;
	temp_node = (*lst);
	(*lst) = NULL;
	while (temp_node)
	{
		del(temp_node->content);
		temp_next = temp_node->next;
		free(temp_node);
		temp_node = temp_next;
	}
}
