/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:42:39 by rabustam          #+#    #+#             */
/*   Updated: 2023/04/10 01:30:28 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_run.h"

static int	get_texture_color(void *texture, int x, int y)
{
	int		color;
	t_img	img;
	void	*temp;

	temp = mlx_get_data_addr (texture, &img.bpp, &img.line_len, &img.endian);
	temp = temp + (x + y * 64) * 4;
	color = *(unsigned char *)(temp + 2) << 16;
	color |= *(unsigned char *)(temp + 1) << 8;
	color |= *(unsigned char *)temp;
	return (color);
}

static void	set_texture(t_cub *cub, t_raycast *rc)
{
	int	precision;

	if (rc->distance_vertical < rc->distance_horizontal)
	{
		precision = (int)(rc->vertical_y * 100) % 100;
		rc->texture_x = cub -> textures.width * precision / 100;
		if (rc->ray_angle < PI / 2 || rc->ray_angle > 3 * PI / 2)
			rc->texture_x = cub -> textures.width - rc->texture_x - 1;
	}
	else
	{
		precision = (int)(rc->horizontal_x * 100) % 100;
		rc->texture_x = cub -> textures.width * precision / 100;
		if (rc->ray_angle > PI)
			rc->texture_x = cub -> textures.width - rc->texture_x - 1;
	}
}

static void	set_3d_cast(t_cub *cub, t_raycast *rc)
{
	rc->cast_angle = cub -> p.ang - rc->ray_angle;
	if (rc->cast_angle < 0)
		rc->cast_angle += 2 * PI;
	if (rc->cast_angle > 2 * PI)
		rc->cast_angle -= 2 * PI;
	rc->distance = rc->distance * cos (rc->cast_angle);
	rc->vertical_line = (WIN_HEIGHT * WIN_WIDTH / WALL_HEIGHT) / rc->distance;
	rc->line_off = WIN_HEIGHT / 2 - rc->vertical_line / 2;
	rc->line_y = 0;
	rc->ray_horizontal_size = WIN_WIDTH / MAX_RAYS;
	set_texture(cub, rc);
}

void	draw_3d_walls(t_cub *cub, t_raycast *rc)
{
	t_coord		start;
	t_coord		end;

	set_3d_cast(cub, rc);
	start.x = rc->ray * rc->ray_horizontal_size;
	end.x = rc->ray * rc->ray_horizontal_size + rc->ray_horizontal_size;
	end.x--;
	while (rc->line_y < rc->vertical_line)
	{
		start.y = rc->line_y + rc->line_off;
		end.y = rc->line_y + rc->line_off;
		rc->texture_y = rc->line_y * cub -> textures.height / rc->vertical_line;
		rc->color = get_texture_color (rc->texture, rc->texture_x, \
										rc->texture_y);
		draw_rectangle (cub, start, end, rc->color);
		rc->line_y++;
	}
}
