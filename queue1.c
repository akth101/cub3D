/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/06/25 16:02:43 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue	*queue_new_node(int y, int x)
{
	t_queue	*node;

	node = ft_calloc(1, sizeof(t_queue));
	if (node == NULL)
		return (NULL);
	node->y = y;
	node->x = x;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	queue_add_front(t_queue **queue, t_queue *new)
{
	if (new == NULL)
		return ;
	if ((*queue) == NULL)
	{
		(*queue) = new;
		return ;
	}
	(*queue)->prev = new;
	new->next = (*queue);
	new->prev = NULL;
	(*queue) = new;
}

void	queue_add_back(t_queue **queue, t_queue *new)
{
	t_queue	*tmp;

	if (new == NULL)
		return ;
	if ((*queue) == NULL)
	{
		(*queue) = new;
		return ;
	}
	tmp = *queue;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;
}

t_queue	*queue_del_front(t_queue **queue)
{
	t_queue	*res;

	res = (*queue);
	if (res == NULL)
		return (NULL);
	(*queue) = (*queue)->next;
	res->next = NULL;
	if ((*queue) == NULL)
		return (res);
	(*queue)->prev = NULL;
	return (res);
}

t_queue	*queue_del_back(t_queue **queue)
{
	t_queue	*tail;
	t_queue	*res;

	tail = (*queue);
	if (tail == NULL)
		return (NULL);
	while (tail->next != NULL)
		tail = tail->next;
	res = tail;
	tail = tail->prev;
	if (res == NULL)
		return (NULL);
	res->prev = NULL;
	if (tail == NULL)
	{
		(*queue) = NULL;
		return (res);
	}
	tail->next = NULL;
	return (res);
}
