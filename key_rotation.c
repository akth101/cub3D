/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:42:33 by seongjko          #+#    #+#             */
/*   Updated: 2024/06/26 20:43:47 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_move_possible(t_struc *struc, int new_x, int new_y)
{
	int	old_x;
	int	old_y;

	old_x = struc->user->pos_x;
	old_y = struc->user->pos_y;
	if (!(0 <= new_x && new_x < struc->screen->worldmap.map_width) || \
		!(0 <= new_y && new_y < struc->screen->worldmap.map_height))
		return (1);
	if (struc->screen->worldmap.worldmap[new_y][old_x] != 0)
		return (1);
	if (struc->screen->worldmap.worldmap[old_y][new_x] != 0)
		return (1);
	return (0);
}

void	rotate_left(t_struc *struc)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = struc->user->dir_x;
	struc->user->dir_x = \
	struc->user->dir_x * cos(-struc->user->rot_speed) \
	- struc->user->dir_y * sin(-struc->user->rot_speed);
	struc->user->dir_y = \
	olddir_x * sin(-struc->user->rot_speed) \
	+ struc->user->dir_y * cos(-struc->user->rot_speed);
	oldplane_x = struc->user->plane_x;
	struc->user->plane_x = \
	struc->user->plane_x * cos(-struc->user->rot_speed) \
	- struc->user->plane_y * sin(-struc->user->rot_speed);
	struc->user->plane_y = \
	oldplane_x * sin(-struc->user->rot_speed) \
	+ struc->user->plane_y * cos(-struc->user->rot_speed);
	return ;
}

void	rotate_right(t_struc *struc)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = struc->user->dir_x;
	struc->user->dir_x = \
	struc->user->dir_x * cos(struc->user->rot_speed) \
	- struc->user->dir_y * sin(struc->user->rot_speed);
	struc->user->dir_y = \
	olddir_x * sin(struc->user->rot_speed) \
	+ struc->user->dir_y * cos(struc->user->rot_speed);
	oldplane_x = struc->user->plane_x;
	struc->user->plane_x = \
	struc->user->plane_x * cos(struc->user->rot_speed) \
	- struc->user->plane_y * sin(struc->user->rot_speed);
	struc->user->plane_y = \
	oldplane_x * sin(struc->user->rot_speed) \
	+ struc->user->plane_y * cos(struc->user->rot_speed);
	return ;
}

int	exit_hook(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}
