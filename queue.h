/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/06/26 19:16:55 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "./libft/libft.h"

typedef struct s_queue {
	int				y;
	int				x;
	struct s_queue	*next;
	struct s_queue	*prev;
}	t_queue;

typedef struct s_pair {
	int	y;
	int	x;
}	t_pair;

t_queue	*queue_new_node(int y, int x);
void	queue_add_front(t_queue **queue, t_queue *new);
void	queue_add_back(t_queue **queue, t_queue *new);
t_queue	*queue_del_front(t_queue **queue);
t_queue	*queue_del_back(t_queue **queue);

long	queue_size(t_queue *queue);
int		queue_empty(t_queue *queue);
void	queue_del_one(t_queue *del_node);
void	queue_del_all(t_queue **queue);

#endif
