/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buffer_util_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:07:34 by seongjko          #+#    #+#             */
/*   Updated: 2024/06/26 22:17:29 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_deltadist(t_calc *var)
{
	var->delta_dist_x = fabs(1 / var->raydir_x);
	var->delta_dist_y = fabs(1 / var->raydir_y);
	return ;
}
