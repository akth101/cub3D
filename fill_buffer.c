/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:38:25 by seongjko          #+#    #+#             */
/*   Updated: 2024/06/26 17:36:40 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_buffer(t_screen *screen)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			screen->buffer[y][x] = 0;
	}
	return ;
}

void	fill_buffer(t_user *user, t_screen *screen)
{
	t_calc	var;
	int		x;

	x = -1;
	while (++x < WIDTH)
	{
		init_vars(user, &var, x);
		shoot_ray(&var, screen);
		fish_eye_correction(&var, user);
		calc_draw_y_coordinates(&var);
		calc_texture(&var, user, screen, x);
		draw_floor_and_ceiling(&var, screen, x);
	}
	return ;
}
