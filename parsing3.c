/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/06/26 20:49:09 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "queue.h"

int	maxi(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

void	extract_map_size(t_map *map, int fd_tmp, int fd_real)
{
	char	*line;
	int		flag;

	flag = 0;
	map->map_width = 0;
	map->map_height = 0;
	while (1)
	{
		line = get_next_line(fd_tmp);
		if (flag == 1 && line == NULL)
			break ;
		if (line[0] == ' ' || line[0] == '1')
		{
			flag = 1;
			map->map_height++;
			map->map_width = maxi(map->map_width, ft_strlen(line) - 1);
		}
		if (flag == 0 && (line == NULL || line[0] != '\n'))
			_error("map invalid", 1);
		if (flag == 1 && !(line[0] == ' ' || line[0] == '1'))
			_error("map invalid", 2);
		if (flag == 0)
			dump_fd(fd_real);
		free(line);
	}
}

void	map_alloc(t_map *map)
{
	int		col_idx;
	int		row_idx;

	row_idx = 0;
	map->worldmap = (int **)ft_calloc(map->map_height, sizeof(int *));
	while (row_idx < map->map_height)
	{
		map->worldmap[row_idx] = (int *)ft_calloc(map->map_width, sizeof(int));
		col_idx = 0;
		while (col_idx < map->map_width)
		{
			map->worldmap[row_idx][col_idx] = -1;
			col_idx++;
		}
		row_idx++;
	}
}

void	check_map_size(t_map *map)
{
	if (map->map_height >= 1000 || map->map_width >= 1000)
		_error("map size too large, >= 1000", 1);
}

void	extract_map(t_map *map, int fd_tmp, int fd_real)
{
	int		col_idx;
	int		row_idx;
	char	*line;

	row_idx = 0;
	extract_map_size(map, fd_tmp, fd_real);
	check_map_size(map);
	map_alloc(map);
	while (row_idx < map->map_height)
	{
		line = get_next_line(fd_real);
		col_idx = 0;
		while (col_idx < map->map_width && line[col_idx] != '\n')
		{
			if (ft_strchr(" 01NSEW", line[col_idx]) == NULL)
				_error("map has invalid character", 1);
			if (line[col_idx] == '0' || line[col_idx] == '1')
				map->worldmap[row_idx][col_idx] = line[col_idx] - '0';
			else if (ft_isalpha(line[col_idx]))
				map->worldmap[row_idx][col_idx] = line[col_idx];
			col_idx++;
		}
		free(line);
		row_idx++;
	}
}
