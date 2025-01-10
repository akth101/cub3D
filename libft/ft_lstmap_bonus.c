/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:17:52 by seongjko          #+#    #+#             */
/*   Updated: 2023/03/26 19:17:53 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_node;
	void	*f_res;

	new_head = NULL;
	new_node = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		f_res = f(lst->content);
		new_node = ft_lstnew(f_res);
		if (!new_node || !f_res)
		{
			del(f_res);
			free(new_node);
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		ft_lstadd_back(&new_head, new_node);
		lst = lst->next;
	}
	return (new_head);
}
