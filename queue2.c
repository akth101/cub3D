/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/06/25 16:03:00 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

long	queue_size(t_queue *queue)
{
	long	res;

	res = 0;
	while (queue != NULL && queue->prev != NULL)
		queue = queue->prev;
	while (queue != NULL)
	{
		res++;
		queue = queue->next;
	}
	return (res);
}

int	queue_empty(t_queue *queue)
{
	return (queue == NULL);
}

void	queue_del_one(t_queue *del_node)
{
	t_queue	*prev_node;
	t_queue	*next_node;

	prev_node = del_node->prev;
	next_node = del_node->next;
	if (prev_node != NULL)
		prev_node->next = next_node;
	if (next_node != NULL)
		next_node->prev = prev_node;
	free(del_node);
}

void	queue_del_all(t_queue **queue)
{
	t_queue	*curr_node;
	t_queue	*del_node;

	curr_node = *queue;
	while (curr_node != NULL)
	{
		del_node = curr_node;
		curr_node = curr_node->next;
		queue_del_one(del_node);
	}
}
