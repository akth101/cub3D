/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:30:08 by seongjko          #+#    #+#             */
/*   Updated: 2024/06/26 20:34:54 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_forward(t_struc *struc)
{
	int	new_x;
	int	new_y;

	new_x = \
	(int)(struc->user->pos_x + struc->user->dir_x * struc->user->move_speed);
	new_y = \
	(int)(struc->user->pos_y + struc->user->dir_y * struc->user->move_speed);
	if (is_move_possible(struc, new_x, new_y))
		return (1);
	if (!struc->screen->worldmap.worldmap[new_y][new_x])
	{
		struc->user->pos_x += struc->user->dir_x * struc->user->move_speed;
		struc->user->pos_y += struc->user->dir_y * struc->user->move_speed;
	}
	return (0);
}

int	move_backward(t_struc *struc)
{
	int	new_x;
	int	new_y;

	new_x = \
	(int)(struc->user->pos_x - struc->user->dir_x * struc->user->move_speed);
	new_y = \
	(int)(struc->user->pos_y - struc->user->dir_y * struc->user->move_speed);
	if (is_move_possible(struc, new_x, new_y))
		return (1);
	if (!struc->screen->worldmap.worldmap[new_y][new_x])
	{
		struc->user->pos_x -= struc->user->dir_x * struc->user->move_speed;
		struc->user->pos_y -= struc->user->dir_y * struc->user->move_speed;
	}
	return (0);
}

int	move_right(t_struc *struc)
{
	int	new_x;
	int	new_y;

	new_x = \
	(int)(struc->user->pos_x + struc->user->plane_x * struc->user->move_speed);
	new_y = \
	(int)(struc->user->pos_y + struc->user->plane_y * struc->user->move_speed);
	if (is_move_possible(struc, new_x, new_y))
		return (1);
	if (!struc->screen->worldmap.worldmap[new_y][new_x])
	{
		struc->user->pos_x += struc->user->plane_x * struc->user->move_speed;
		struc->user->pos_y += struc->user->plane_y * struc->user->move_speed;
	}
	return (0);
}

int	move_left(t_struc *struc)
{
	int	new_x;
	int	new_y;

	new_x = \
	(int)(struc->user->pos_x - struc->user->plane_x * struc->user->move_speed);
	new_y = \
	(int)(struc->user->pos_y - struc->user->plane_y * struc->user->move_speed);
	if (is_move_possible(struc, new_x, new_y))
		return (1);
	if (!struc->screen->worldmap.worldmap[new_y][new_x])
	{
		struc->user->pos_x -= struc->user->plane_x * struc->user->move_speed;
		struc->user->pos_y -= struc->user->plane_y * struc->user->move_speed;
	}
	return (0);
}

int	key_press(int key, t_struc *struc)
{
	int	is_out_of_map;

	is_out_of_map = 0;
	if (key == FORWARD)
		is_out_of_map = move_forward(struc);
	if (key == BACKWARD)
		is_out_of_map = move_backward(struc);
	if (key == RIGHT)
		is_out_of_map = move_right(struc);
	if (key == LEFT)
		is_out_of_map = move_left(struc);
	if (key == ROTATE_LEFT)
		rotate_left(struc);
	if (key == ROTATE_RIGHT)
		rotate_right(struc);
	if (key == ESC)
	{
		mlx_destroy_window(struc->mlx->mlx, struc->mlx->win);
		exit(0);
	}
	if (!is_out_of_map)
		draw_new_img(struc);
	return (0);
}
