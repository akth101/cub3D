/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/06/26 20:33:46 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "queue.h"

int	element_to_int(char *element)
{
	if (ft_strncmp(element, "NO", 3) == 0)
		return (0);
	else if (ft_strncmp(element, "SO", 3) == 0)
		return (1);
	else if (ft_strncmp(element, "EA", 3) == 0)
		return (2);
	else if (ft_strncmp(element, "WE", 3) == 0)
		return (3);
	else if (ft_strncmp(element, "F", 2) == 0)
		return (4);
	else if (ft_strncmp(element, "C", 2) == 0)
		return (5);
	return (-1);
}

int	identifier_parsing(t_screen *screen, char *line, int *count)
{
	char	**split_line;
	int		element;

	split_line = ft_split(line, ' ');
	if (!split_line || split_line[0] == NULL || \
		split_line[1] == NULL || split_line[2] != NULL)
		return (free_split(split_line, 1));
	element = element_to_int(split_line[0]);
	if (element == -1)
		return (free_split(split_line, 2));
	if ((*count & (1 << element)) != 0)
		return (free_split(split_line, 3));
	split_line[1][ft_strlen(split_line[1]) - 1] = '\0';
	if (element < 4)
		screen->tex_ary[element].tex_path = ft_strdup(split_line[1]);
	else if (element == 4)
		screen->floor = color_data_extract(split_line[1]);
	else if (element == 5)
		screen->ceiling = color_data_extract(split_line[1]);
	if (screen->floor == -1 || screen->ceiling == -1)
		return (free_split(split_line, 4));
	*count |= (1 << element);
	return (free_split(split_line, 0));
}

void	dump_fd(int fd)
{
	char	*res;

	res = get_next_line(fd);
	free(res);
}

int	extract_texture(t_screen *screen, int fd_tmp, int fd_real)
{
	int		res;
	int		count;
	char	*line;

	count = 0;
	while (count != ((1 << 6) - 1))
	{
		line = get_next_line(fd_tmp);
		dump_fd(fd_real);
		if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		if (ft_strchr("NSWEFC", line[0]) == NULL)
			_error("invalid identifier", 2);
		res = identifier_parsing(screen, line, &count);
		if (res)
			_error("identifier parsing failed", res);
		free(line);
	}
	return (0);
}
