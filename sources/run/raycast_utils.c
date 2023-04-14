/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:40:38 by rabustam          #+#    #+#             */
/*   Updated: 2023/04/04 17:27:40 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_run.h"

float	dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	choose_wall(t_cub *cub, t_raycast *rc)
{
	int	map_x;
	int	map_y;

	reset_params(cub, rc);
	set_h_rays(cub, rc);
	while (rc->deep_of_field < rc->deep_of_field_max)
	{
		map_x = (int)(rc->ray_x);
		map_y = (int)(rc->ray_y);
		h_wall_hit(cub, rc, map_x, map_y);
	}
	set_v_rays(cub, rc);
	while (rc->deep_of_field < rc->deep_of_field_max)
	{
		map_x = (int)(rc->ray_x);
		map_y = (int)(rc->ray_y);
		v_wall_hit(cub, rc, map_x, map_y);
	}
}

void	choose_texture(t_cub *cub, t_raycast *rc)
{
	if (rc->distance_vertical < rc->distance_horizontal)
	{
		rc->ray_x = rc->vertical_x;
		rc->ray_y = rc->vertical_y;
		rc->distance = rc->distance_vertical;
		if (rc->ray_angle > PI / 2 && rc->ray_angle < 3 * PI / 2)
			rc->texture = cub -> textures.east_image;
		else
			rc->texture = cub -> textures.west_image;
	}
	else
	{
		rc->ray_x = rc->horizontal_x;
		rc->ray_y = rc->horizontal_y;
		rc->distance = rc->distance_horizontal;
		if (rc->ray_angle > PI)
			rc->texture = cub -> textures.south_image;
		else
			rc->texture = cub -> textures.north_image;
	}
}
