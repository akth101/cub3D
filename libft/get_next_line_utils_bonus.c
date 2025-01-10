/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:48:07 by tajeong           #+#    #+#             */
/*   Updated: 2023/11/15 12:55:40 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*gnl_calloc(int count, int size)
{
	char	*res;
	int		idx;

	idx = 0;
	if (count * size == 0)
		return (NULL);
	res = (char *)malloc(count * size);
	if (res == NULL)
		return (NULL);
	while (idx < count * size)
	{
		res[idx] = '\0';
		idx++;
	}
	return ((void *)res);
}

char	*gnl_error(t_save *save, int malloc_flag)
{
	if (malloc_flag)
		free(save->str);
	save->str = NULL;
	save->size = 0;
	save->last_idx = 0;
	save->eof_flag = 0;
	return (NULL);
}

char	*gnl_resize_str(t_save *save)
{
	int		extends_size;
	int		idx;
	char	*res;

	extends_size = save->size * 2;
	if (save->str == NULL)
		extends_size = BUFFER_SIZE;
	res = gnl_calloc(extends_size + 1, sizeof(char));
	if (res == NULL)
		return (gnl_error(save, save->str != NULL));
	idx = 0;
	while (idx < save->last_idx)
	{
		res[idx] = save->str[idx];
		idx++;
	}
	free(save->str);
	save->size = extends_size;
	return (res);
}

char	*gnl_split_endl(t_save *save)
{
	const int	endl_idx = gnl_findchr(save, '\n');
	int			idx;
	int			memmove_idx;
	char		*res;

	idx = 0;
	memmove_idx = 0;
	res = gnl_calloc(endl_idx + 2, sizeof(char));
	if (res == NULL)
		return (NULL);
	while (idx < endl_idx + 1)
	{
		res[idx] = save->str[idx];
		idx++;
	}
	gnl_memmove(save, idx);
	return (res);
}

void	gnl_memmove(t_save *save, int idx)
{
	int	memmove_idx;

	memmove_idx = 0;
	while (idx < save->last_idx)
	{
		save->str[memmove_idx] = save->str[idx];
		idx++;
		memmove_idx++;
	}
	save->last_idx = memmove_idx;
	while (memmove_idx < save->size)
	{
		save->str[memmove_idx] = '\0';
		memmove_idx++;
	}
}
