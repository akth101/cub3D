/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/06/26 19:10:44 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "queue.h"

void	_error(char *msg, int error_code)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(error_code);
}

int	check_file_name(char *path)
{
	int	path_len;

	path_len = ft_strlen(path);
	if (path_len < 5 || \
		!(path[path_len - 4] == '.' && \
		path[path_len - 3] == 'c' && \
		path[path_len - 2] == 'u' && \
		path[path_len - 1] == 'b'))
		return (1);
	return (0);
}

int	check_num(char *num)
{
	while (*num)
	{
		if (ft_isalpha(*num))
			return (1);
		num++;
	}
	return (0);
}

int	free_split(char **split_res, int code)
{
	int	idx;

	idx = 0;
	while (split_res[idx])
	{
		free(split_res[idx]);
		idx++;
	}
	free(split_res);
	return (code);
}

int	color_data_extract(char *color)
{
	char	**split_line;
	int		colori;

	split_line = ft_split(color, ',');
	if (!split_line || \
		split_line[0] == NULL || \
		split_line[1] == NULL || \
		split_line[2] == NULL || \
		split_line[3] != NULL)
		return (free_split(split_line, -1));
	colori = 0;
	if (check_num(split_line[0]) || \
		check_num(split_line[1]) || \
		check_num(split_line[2]))
		return (free_split(split_line, -1));
	if (!(0 <= ft_atoi(split_line[0]) && ft_atoi(split_line[0]) <= 255) || \
		!(0 <= ft_atoi(split_line[1]) && ft_atoi(split_line[1]) <= 255) || \
		!(0 <= ft_atoi(split_line[2]) && ft_atoi(split_line[2]) <= 255))
		return (free_split(split_line, -1));
	colori += (ft_atoi(split_line[0]) << 16);
	colori += (ft_atoi(split_line[1]) << 8);
	colori += ft_atoi(split_line[2]);
	free_split(split_line, 0);
	return (colori);
}
