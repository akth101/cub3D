/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/06/26 19:12:38 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "queue.h"

void	flood(t_map *map, int **visited, t_queue **queue, t_pair coor)
{
	t_queue	*new_data;
	int		y;
	int		x;

	y = coor.y;
	x = coor.x;
	if (!(0 <= y && y < map->map_height && \
		0 <= x && x < map->map_width))
		_error("map invalid", 1);
	if (0 <= y && y < map->map_height && 0 <= x && \
		x < map->map_width && map->worldmap[y][x] == -1)
		_error("map invalid", 2);
	if (0 <= y && y < map->map_height && \
		0 <= x && x < map->map_width && \
		map->worldmap[y][x] != -1 && \
		map->worldmap[y][x] != 1 && visited[y][x] == 0)
	{
		visited[y][x] = 1;
		new_data = queue_new_node(y, x);
		queue_add_back(queue, new_data);
	}
}

void	bfs(t_map *map, int **visited, int y, int x)
{
	t_queue	*data;
	t_queue	*queue;

	queue = queue_new_node(y, x);
	visited[y][x] = 1;
	while (!queue_empty(queue))
	{
		data = queue_del_front(&queue);
		flood(map, visited, &queue, (t_pair){data->y + 1, data->x});
		flood(map, visited, &queue, (t_pair){data->y - 1, data->x});
		flood(map, visited, &queue, (t_pair){data->y, data->x + 1});
		flood(map, visited, &queue, (t_pair){data->y, data->x - 1});
		free(data);
	}
}

void	visited_free(t_map *map, int **visited)
{
	int	idx;

	idx = 0;
	while (idx < map->map_height)
	{
		free(visited[idx]);
		idx++;
	}
	free(visited);
}

int	**visited_alloc(t_map *map)
{
	int	**visited;
	int	idx;

	visited = (int **)ft_calloc(map->map_height, sizeof(int *));
	idx = 0;
	while (idx < map->map_height)
	{
		visited[idx] = (int *)ft_calloc(map->map_width, sizeof(int));
		idx++;
	}
	return (visited);
}
