/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_calc_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:36:30 by seongjko          #+#    #+#             */
/*   Updated: 2024/06/26 18:45:10 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_texture_vars(t_calc *var, t_user *user, t_screen *screen)
{
	int	tex_height;
	int	tex_width;

	tex_height = screen->tex_ary[var->tex_num].tex_height;
	tex_width = screen->tex_ary[var->tex_num].tex_width;
	if (var->side == 0)
		var->wall_x = user->pos_y + var->perpwall_dist * var->raydir_y;
	else
		var->wall_x = user->pos_x + var->perpwall_dist * var->raydir_x;
	var->wall_x -= floor(var->wall_x);
	var->tex_x = (int)(var->wall_x * (double)tex_width);
	if (var->side == 0 && var->raydir_x > 0)
		var->tex_x = tex_width - var->tex_x - 1;
	if (var->side == 1 && var->raydir_y < 0)
		var->tex_x = tex_width - var->tex_x - 1;
	var->step = 1.0 * tex_height / var->line_height;
	var->tex_pos = \
	(var->draw_start - HEIGHT / 2 + var->line_height / 2) * var->step;
	return ;
}

void	select_wall_texture(t_calc *var)
{
	if (var->side == 1)
	{
		if (var->raydir_y < 0)
			var->tex_num = 0;
		else if (var->raydir_y > 0)
			var->tex_num = 1;
	}
	if (var->side == 0)
	{
		if (var->raydir_x < 0)
			var->tex_num = 3;
		else if (var->raydir_x > 0)
			var->tex_num = 2;
	}
	return ;
}

void	calc_texture_coor(t_calc *var, t_screen *screen, int x)
{
	int	y;
	int	color;
	int	tex_height;
	int	tex_width;

	tex_height = screen->tex_ary[var->tex_num].tex_height;
	tex_width = screen->tex_ary[var->tex_num].tex_width;
	y = var->draw_start;
	while (y < var->draw_end)
	{
		var->tex_y = (int)var->tex_pos & (tex_height - 1);
		var->tex_pos += var->step;
		color = \
		screen->tex_ary[var->tex_num].\
		tex_data[tex_height * var->tex_y + var->tex_x];
		if (var->side == 1)
			color = (color >> 1) & 8355711;
		screen->buffer[y][x] = color;
		y++;
	}
	return ;
}

void	calc_texture(t_calc *var, t_user *user, t_screen *screen, int x)
{
	select_wall_texture(var);
	calc_texture_vars(var, user, screen);
	calc_texture_coor(var, screen, x);
}
