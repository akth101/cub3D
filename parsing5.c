/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/06/26 19:16:39 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "queue.h"

void	check_map(t_map *map)
{
	int	row_idx;
	int	col_idx;
	int	**visited;

	visited = visited_alloc(map);
	row_idx = 0;
	while (row_idx < map->map_height)
	{
		col_idx = 0;
		while (col_idx < map->map_width)
		{
			if (map->worldmap[row_idx][col_idx] == 0 && \
				visited[row_idx][col_idx] == 0)
			{
				bfs(map, visited, row_idx, col_idx);
			}
			col_idx++;
		}
		row_idx++;
	}
	visited_free(map, visited);
}

void	check_map_character(t_map *map)
{
	int	row_idx;
	int	col_idx;
	int	user;

	user = 0;
	row_idx = 0;
	while (row_idx < map->map_height)
	{
		col_idx = 0;
		while (col_idx < map->map_width)
		{
			if (map->worldmap[row_idx][col_idx] == 'N' || \
				map->worldmap[row_idx][col_idx] == 'S' || \
				map->worldmap[row_idx][col_idx] == 'E' || \
				map->worldmap[row_idx][col_idx] == 'W')
				user++;
			col_idx++;
		}
		row_idx++;
	}
	if (user != 1)
		_error("invalid user", 1);
}

void	parsing_map(t_screen *screen, char *path)
{
	int	fd_tmp;
	int	fd_real;

	if (check_file_name(path))
		_error("file format invalid", 1);
	fd_tmp = open(path, O_RDONLY);
	if (fd_tmp == -1)
		_error("map file invalid", 2);
	fd_real = open(path, O_RDONLY);
	if (fd_real == -1)
	{
		close(fd_tmp);
		_error("map file invalid", 2);
	}
	extract_texture(screen, fd_tmp, fd_real);
	extract_map(&screen->worldmap, fd_tmp, fd_real);
	close(fd_tmp);
	close(fd_real);
	check_map_character(&screen->worldmap);
	check_map(&screen->worldmap);
}
