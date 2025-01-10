/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:30:31 by seongjko          #+#    #+#             */
/*   Updated: 2024/06/26 17:37:45 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor(t_calc *var, t_screen *screen, int x)
{
	int	y;

	y = var->draw_end;
	while (y < HEIGHT)
	{
		screen->buffer[y][x] = screen->floor;
		y++;
	}
	return ;
}

void	draw_ceiling(t_calc *var, t_screen *screen, int x)
{
	int	y;

	y = -1;
	while (++y < var->draw_start)
		screen->buffer[y][x] = screen->ceiling;
	return ;
}

void	draw_floor_and_ceiling(t_calc *var, t_screen *screen, int x)
{
	draw_ceiling(var, screen, x);
	draw_floor(var, screen, x);
	return ;
}
