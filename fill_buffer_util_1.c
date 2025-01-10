/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buffer_util_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:31:19 by seongjko          #+#    #+#             */
/*   Updated: 2024/06/26 17:37:23 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_step_and_sidedist(t_user *user, t_calc *var)
{
	if (var->raydir_x < 0)
	{
		var->step_x = -1;
		var->side_dist_x = (user->pos_x - var->map_x) * var->delta_dist_x;
	}
	else
	{
		var->step_x = 1;
		var->side_dist_x = (var->map_x + 1.0 - user->pos_x) * var->delta_dist_x;
	}
	if (var->raydir_y < 0)
	{
		var->step_y = -1;
		var->side_dist_y = (user->pos_y - var->map_y) * var->delta_dist_y;
	}
	else
	{
		var->step_y = 1;
		var->side_dist_y = (var->map_y + 1.0 - user->pos_y) * var->delta_dist_y;
	}
	return ;
}

void	init_vars(t_user *user, t_calc *var, int x)
{
	var->camera_x = 2 * x / (double)WIDTH - 1;
	var->raydir_x = user->dir_x + user->plane_x * var->camera_x;
	var->raydir_y = user->dir_y + user->plane_y * var->camera_x;
	var->map_x = (int)user->pos_x;
	var->map_y = (int)user->pos_y;
	var->hit = 0;
	init_deltadist(var);
	init_step_and_sidedist(user, var);
	return ;
}

void	shoot_ray(t_calc *var, t_screen *screen)
{
	while (var->hit == 0)
	{
		if (var->side_dist_x < var->side_dist_y)
		{
			var->side_dist_x += var->delta_dist_x;
			var->map_x += var->step_x;
			var->side = 0;
		}
		else
		{
			var->side_dist_y += var->delta_dist_y;
			var->map_y += var->step_y;
			var->side = 1;
		}
		if (screen->worldmap.worldmap[var->map_y][var->map_x] > 0)
			var->hit = 1;
	}
	return ;
}

void	fish_eye_correction(t_calc *var, t_user *user)
{
	if (var->side == 0)
		var->perpwall_dist = \
		(var->map_x - user->pos_x + (1 - var->step_x) / 2) / var->raydir_x;
	else
		var->perpwall_dist = \
		(var->map_y - user->pos_y + (1 - var->step_y) / 2) / var->raydir_y;
	if (fabs(var->perpwall_dist) < NEAR_ZERO)
		var->perpwall_dist = 0.01;
	return ;
}

void	calc_draw_y_coordinates(t_calc *var)
{
	var->line_height = (int)(HEIGHT / var->perpwall_dist);
	var->draw_start = HEIGHT / 2 - var->line_height / 2;
	if (var->draw_start < 0)
		var->draw_start = 0;
	var->draw_end = HEIGHT / 2 + var->line_height / 2;
	if (var->draw_end >= HEIGHT)
		var->draw_end = HEIGHT - 1;
	return ;
}
