/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:30:38 by seongjko          #+#    #+#             */
/*   Updated: 2024/06/26 15:47:08 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	execution_main(t_user *user, t_mlx *mlx, t_screen *screen)
{
	clear_buffer(screen);
	fill_buffer(user, screen);
	draw_buffer(mlx, screen);
	return ;
}
