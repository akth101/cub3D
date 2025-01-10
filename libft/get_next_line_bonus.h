/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:48:07 by tajeong           #+#    #+#             */
/*   Updated: 2023/12/29 20:38:51 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef MAX_FD_SIZE
#  define MAX_FD_SIZE 104960
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_save {
	char	*str;
	int		size;
	int		last_idx;
	int		eof_flag;
}	t_save;

int		gnl_findchr(t_save *save, char c);
char	*gnl_strdup(t_save *save);
void	gnl_getline(t_save *save, int fd);
char	*get_next_line(int fd);
void	*gnl_calloc(int count, int size);
char	*gnl_error(t_save *save, int malloc_flag);
char	*gnl_resize_str(t_save *save);
char	*gnl_split_endl(t_save *save);
void	gnl_memmove(t_save *save, int idx);

#endif
