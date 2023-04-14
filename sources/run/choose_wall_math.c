/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_wall_math.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:38:17 by rabustam          #+#    #+#             */
/*   Updated: 2023/04/04 17:29:00 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_run.h"

void	reset_params(t_cub *cub, t_raycast *rc)
{
	rc->distance_vertical = 1000000000;
	rc->distance_horizontal = 1000000000;
	rc->distance = 1000000000;
	if (rc->ray_angle < 0)
		rc->ray_angle += 2 * PI;
	if (rc->ray_angle > 2 * PI)
		rc->ray_angle -= 2 * PI;
	rc->deep_of_field = 0;
	rc->horizontal_x = cub -> p.x;
	rc->horizontal_y = cub -> p.y;
	rc->horizontal_tan = -1 / tan (rc->ray_angle);
}

void	set_h_rays(t_cub *cub, t_raycast *rc)
{
	if (rc->ray_angle < PI)
	{
		rc->ray_y = (int) cub -> p.y - PRECISION_DOWN;
		rc->ray_x = (cub -> p.y - rc->ray_y) * rc->horizontal_tan + cub -> p.x;
		rc->ray_y_offset = -PRECISION_UP;
		rc->ray_x_offset = -rc->ray_y_offset * rc->horizontal_tan;
	}
	if (rc->ray_angle > PI)
	{
		rc->ray_y = (int) cub -> p.y + PRECISION_UP;
		rc->ray_x = (cub -> p.y - rc->ray_y) * rc->horizontal_tan + cub -> p.x;
		rc->ray_y_offset = PRECISION_UP;
		rc->ray_x_offset = -rc->ray_y_offset * rc->horizontal_tan;
	}
	if (rc->ray_angle == 0 || rc->ray_angle == PI)
	{
		rc->ray_x = cub -> p.x;
		rc->ray_y = cub -> p.y;
		rc->deep_of_field = rc->deep_of_field_max;
	}
}

void	h_wall_hit(t_cub *cub, t_raycast *rc, int map_x, int map_y)
{
	if (map_x >= 0 && \
		map_y >= 0 && \
		map_x < cub -> map_width && \
		map_y < cub -> map_height && \
		cub -> scene_map[map_y][map_x] == '1'
	)
	{
		rc->horizontal_x = rc->ray_x;
		rc->horizontal_y = rc->ray_y;
		rc->distance_horizontal = dist (cub -> p.x, cub -> p.y, \
										rc->horizontal_x, rc->horizontal_y);
		rc->deep_of_field = rc->deep_of_field_max;
	}
	else
	{
		rc->ray_x += rc->ray_x_offset;
		rc->ray_y += rc->ray_y_offset;
		rc->deep_of_field++;
	}
}

void	set_v_rays(t_cub *cub, t_raycast *rc)
{
	rc->deep_of_field = 0;
	rc->vertical_x = cub -> p.x;
	rc->vertical_y = cub -> p.y;
	rc->vertical_tan = -tan (rc->ray_angle);
	if (rc->ray_angle < PI / 2 || rc->ray_angle > 3 * PI / 2)
	{
		rc->ray_x = (int) cub -> p.x - PRECISION_DOWN;
		rc->ray_y = (cub -> p.x - rc->ray_x) * rc->vertical_tan + cub -> p.y;
		rc->ray_x_offset = -PRECISION_UP;
		rc->ray_y_offset = -rc->ray_x_offset * rc->vertical_tan;
	}
	if (rc->ray_angle > PI / 2 && rc->ray_angle < 3 * PI / 2)
	{
		rc->ray_x = (int) cub -> p.x + PRECISION_UP;
		rc->ray_y = (cub -> p.x - rc->ray_x) * rc->vertical_tan + cub -> p.y;
		rc->ray_x_offset = PRECISION_UP;
		rc->ray_y_offset = -rc->ray_x_offset * rc->vertical_tan;
	}
	if (rc->ray_angle == PI / 2 || rc->ray_angle == 3 * PI / 2)
	{
		rc->ray_x = cub -> p.x;
		rc->ray_y = cub -> p.y;
		rc->deep_of_field = rc->deep_of_field_max;
	}
}

void	v_wall_hit(t_cub *cub, t_raycast *rc, int map_x, int map_y)
{
	if (map_x >= 0 && \
		map_y >= 0 && \
		map_x < cub -> map_width && \
		map_y < cub -> map_height && \
		cub -> scene_map[map_y][map_x] == '1'
	)
	{
		rc->vertical_x = rc->ray_x;
		rc->vertical_y = rc->ray_y;
		rc->distance_vertical = dist (cub -> p.x, cub -> p.y, \
										rc->vertical_x, rc->vertical_y);
		rc->deep_of_field = rc->deep_of_field_max;
	}
	else
	{
		rc->ray_x += rc->ray_x_offset;
		rc->ray_y += rc->ray_y_offset;
		rc->deep_of_field++;
	}
}
