/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:14:07 by seongjko          #+#    #+#             */
/*   Updated: 2024/06/26 20:00:28 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file_extension(t_screen *screen, int i)
{
	const char	*ext;
	char		*tex_path;
	int			path_len;
	int			ext_len;

	ext = ".xpm";
	tex_path = screen->tex_ary[i].tex_path;
	path_len = ft_strlen(tex_path);
	ext_len = ft_strlen(ext);
	return (ft_strncmp(tex_path + (path_len - ext_len), ext, ext_len));
}

int	check_texture_path(t_screen *screen)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (check_file_extension(screen, i) != 0)
			return (0);
	}
	return (1);
}
