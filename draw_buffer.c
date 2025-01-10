/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:30:45 by seongjko          #+#    #+#             */
/*   Updated: 2024/06/26 18:43:30 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (!(0 <= x && x <= 1920) || !(0 <= y && y <= 1080))
		return ;
	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_buffer(t_mlx *mlx, t_screen *screen)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			my_mlx_pixel_put(mlx, x, y, screen->buffer[y][x]);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return ;
}

void	draw_new_img(t_struc *struc)
{
	mlx_destroy_image(struc->mlx->mlx, struc->mlx->img);
	struc->mlx->img = mlx_new_image(struc->mlx->mlx, 1920, 1080);
	struc->mlx->addr = mlx_get_data_addr(\
	struc->mlx->img, &struc->mlx->bits_per_pixel, \
	&struc->mlx->line_length, &struc->mlx->endian);
	execution_main(struc->user, struc->mlx, struc->screen);
	return ;
}
