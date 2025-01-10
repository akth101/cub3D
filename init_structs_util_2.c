/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs_util_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:41:15 by seongjko          #+#    #+#             */
/*   Updated: 2024/06/26 20:34:15 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_user_vector(t_user *user, t_screen *screen, int y, int x)
{
	user->pos_x = x + 0.5;
	user->pos_y = y + 0.5;
	if (screen->worldmap.worldmap[y][x] == 'N' || \
		screen->worldmap.worldmap[y][x] == 'S')
	{
		user->dir_x = 0;
		if (screen->worldmap.worldmap[y][x] == 'N')
			user->dir_y = -1;
		else
			user->dir_y = 1;
	}
	if (screen->worldmap.worldmap[y][x] == 'E' || \
		screen->worldmap.worldmap[y][x] == 'W')
	{
		user->dir_y = 0;
		if (screen->worldmap.worldmap[y][x] == 'E')
			user->dir_x = 1;
		else
			user->dir_x = -1;
	}
	return ;
}

void	init_camera_plane(t_user *user, t_screen *screen, int y, int x)
{
	if (screen->worldmap.worldmap[y][x] == 'N')
	{
		user->plane_x = 0.66;
		user->plane_y = 0;
	}
	if (screen->worldmap.worldmap[y][x] == 'S')
	{
		user->plane_x = -0.66;
		user->plane_y = 0;
	}
	if (screen->worldmap.worldmap[y][x] == 'W')
	{
		user->plane_x = 0;
		user->plane_y = -0.66;
	}
	if (screen->worldmap.worldmap[y][x] == 'E')
	{
		user->plane_x = 0;
		user->plane_y = 0.66;
	}
	return ;
}

void	init_tex_ary(t_mlx *mlx, t_screen *screen)
{
	int	i;

	i = -1;
	if (!check_texture_path(screen))
	{
		perror("Error\nre-check texture path");
		exit(1);
	}
	while (++i < 4)
	{
		screen->tex_ary[i].img = mlx_xpm_file_to_image(\
		mlx->mlx, \
		screen->tex_ary[i].tex_path, &screen->tex_ary[i].tex_width, \
		&screen->tex_ary[i].tex_height);
		if (screen->tex_ary[i].img == NULL)
		{
			mlx_destroy_window(mlx->mlx, mlx->win);
			perror("Error\nmlx_xpm_file_to_image failed\n");
			exit(1);
		}
		screen->tex_ary[i].tex_data = (unsigned int *)mlx_get_data_addr(\
			screen->tex_ary[i].img, &screen->tex_ary[i].bits_per_pixel, \
			&screen->tex_ary[i].size_line, &screen->tex_ary[i].endian);
	}
	return ;
}
