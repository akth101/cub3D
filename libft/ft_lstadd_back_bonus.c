/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:28:48 by seongjko          #+#    #+#             */
/*   Updated: 2023/03/23 21:28:49 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	head = *lst;
	if (head == NULL)
	{
		*lst = new;
		return ;
	}
	while (1)
	{
		if (head->next == 0)
		{
			head->next = new;
			break ;
		}
		head = head->next;
	}
}
