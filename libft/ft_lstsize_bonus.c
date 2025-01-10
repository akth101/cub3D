/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:20:52 by seongjko          #+#    #+#             */
/*   Updated: 2023/03/23 21:20:54 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cnt;
	t_list	*head;

	cnt = 0;
	head = lst;
	while (head)
	{
		head = head -> next;
		cnt++;
	}
	return (cnt);
}
