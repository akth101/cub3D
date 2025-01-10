/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:30:16 by seongjko          #+#    #+#             */
/*   Updated: 2024/06/26 19:00:01 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_structs(t_user *user, t_mlx *mlx, t_screen *screen)
{
	init_user(user, screen);
	init_mlx(mlx);
	init_screen(mlx, screen);
	return ;
}
