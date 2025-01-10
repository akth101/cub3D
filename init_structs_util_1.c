/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs_util_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:41:00 by seongjko          #+#    #+#             */
/*   Updated: 2024/06/26 20:34:07 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_user(t_user *user, t_screen *screen)
{
	int	y;
	int	x;

	user->move_speed = 0.05;
	user->rot_speed = 0.05;
	y = -1;
	while (++y < screen->worldmap.map_height)
	{
		x = -1;
		while (++x < screen->worldmap.map_width)
		{
			if (screen->worldmap.worldmap[y][x] == 'N' || \
				screen->worldmap.worldmap[y][x] == 'S' || \
				screen->worldmap.worldmap[y][x] == 'W' || \
				screen->worldmap.worldmap[y][x] == 'E')
			{
				set_user_vector(user, screen, y, x);
				init_camera_plane(user, screen, y, x);
				screen->worldmap.worldmap[y][x] = 0;
				return ;
			}
		}
	}
	return ;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
	{
		perror("Error\nfailed initiating mlx instance\n");
		exit(1);
	}
	mlx->win = mlx_new_window(mlx->mlx, 1920, 1080, "cub3d!");
	if (mlx->win == NULL)
	{
		perror("Error\nfailed initiating window instance\n");
		exit(1);
	}
	mlx->img = mlx_new_image(mlx->mlx, 1920, 1080);
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel), \
	&(mlx->line_length), &mlx->endian);
	return ;
}

void	init_screen(t_mlx *mlx, t_screen *screen)
{
	int	i;
	int	y;
	int	x;

	screen->buffer = (int **)malloc(sizeof(int *) * HEIGHT);
	i = -1;
	while (++i < HEIGHT)
		screen->buffer[i] = (int *)malloc(sizeof(int *) * WIDTH);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			screen->buffer[y][x] = 0;
	}
	init_tex_ary(mlx, screen);
	return ;
}
