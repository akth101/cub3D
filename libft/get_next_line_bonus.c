/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:48:07 by tajeong           #+#    #+#             */
/*   Updated: 2023/11/15 12:55:50 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	gnl_findchr(t_save *save, char c)
{
	int	idx;

	idx = 0;
	while (idx < save->last_idx)
	{
		if (save->str[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}

char	*gnl_strdup(t_save *save)
{
	int		idx;
	char	*res;

	res = gnl_calloc(save->last_idx + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	idx = 0;
	while (idx < save->last_idx)
	{
		res[idx] = save->str[idx];
		idx++;
	}
	return (res);
}

void	gnl_getline(t_save *save, int fd)
{
	int	read_size;

	read_size = 0;
	while (save->eof_flag == 0 && gnl_findchr(save, '\n') == -1)
	{
		if (save->size - save->last_idx < BUFFER_SIZE)
			save->str = gnl_resize_str(save);
		if (save->str == NULL)
			return ;
		read_size = read(fd, &(save->str[save->last_idx]), BUFFER_SIZE);
		save->last_idx += read_size;
		if (read_size == 0)
			save->eof_flag = 1;
		if (read_size == -1)
		{
			gnl_error(save, 1);
			return ;
		}
	}
}

char	*get_next_line(int fd)
{
	static t_save	saves[MAX_FD_SIZE];
	char			*res;

	if (fd < 0 || fd >= MAX_FD_SIZE || BUFFER_SIZE < 1)
		return (NULL);
	gnl_getline(&(saves[fd]), fd);
	if (saves[fd].str == NULL)
		return (NULL);
	if (saves[fd].eof_flag == 0 || \
	gnl_findchr(&(saves[fd]), '\n') != -1)
		res = gnl_split_endl(&(saves[fd]));
	else
	{
		if (saves[fd].str[0] == '\0')
			res = NULL;
		else
			res = gnl_strdup(&(saves[fd]));
		if (res != NULL)
			gnl_error(&(saves[fd]), 1);
	}
	if (res == NULL)
		return (gnl_error(&(saves[fd]), 1));
	return (res);
}
