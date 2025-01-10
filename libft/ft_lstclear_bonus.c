/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:07:48 by seongjko          #+#    #+#             */
/*   Updated: 2023/03/26 14:07:49 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;

	head = *lst;
	while (head)
	{
		del(head->content);
		temp = head->next;
		head->next = NULL;
		free(head);
		head = NULL;
		head = temp;
	}
	*lst = NULL;
}
