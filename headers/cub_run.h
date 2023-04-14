/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_run.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:22:58 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/03/23 16:22:58 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_RUN_H
# define CUB_RUN_H

# include <mlx.h>

# include "structs.h"
# include "cub_init.h"
# include "cub_exit.h"

# define ESC_KEY 65307
# define LEFT_KEY 65361
# define UP_KEY 65362
# define RIGHT_KEY 65363
# define DOWN_KEY 65364

# define LEFT 1
# define RIGHT 2

# define PRESSED 1
# define RELEASED 2

# define PI 3.1415
# define DR 0.0174533

# define MAX_DIST 1000000000
# define MAX_RAYS 480
# define RAY_HORIZONTAL_SIZE 16
# define FOV 60
# define WALL_HEIGHT 700

# define PRECISION_DOWN 0.00001
# define PRECISION_UP 1

# define STEPS 0.25
# define TURN_ANG 0.07

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_raycast
{
	int		deep_of_field;
	int		deep_of_field_max;
	void	*texture;
	int		texture_x;
	int		texture_y;
	int		color;
	int		ray;
	float	ray_x;
	float	ray_y;
	float	ray_angle;
	float	ray_x_offset;
	float	ray_y_offset;
	int		ray_horizontal_size;
	float	distance;
	float	distance_horizontal;
	float	horizontal_x;
	float	horizontal_y;
	float	horizontal_tan;
	float	distance_vertical;
	float	vertical_x;
	float	vertical_y;
	float	vertical_tan;
	int		vertical_line;
	float	cast_angle;
	int		line_off;
	int		line_y;
}	t_raycast;

void	cub_run(t_cub *cub);
int		button_down(int key_code, t_cub *cub);
int		button_up(int key_code, t_cub *cub);
void	check_keys(t_cub *cub);
void	draw_pixel(t_img *img, int x, int y, int color);
void	draw_background(t_cub *cub);
void	draw_rectangle(t_cub *cub, t_coord start, t_coord end, int color);
void	raycast(t_cub *cub);
void	reset_params(t_cub *cub, t_raycast *rc);
void	set_h_rays(t_cub *cub, t_raycast *rc);
void	h_wall_hit(t_cub *cub, t_raycast *rc, int map_x, int map_y);
void	set_v_rays(t_cub *cub, t_raycast *rc);
void	v_wall_hit(t_cub *cub, t_raycast *rc, int map_x, int map_y);
void	draw_3d_walls(t_cub *cub, t_raycast *rc);
void	choose_texture(t_cub *cub, t_raycast *rc);
void	choose_wall(t_cub *cub, t_raycast *rc);
float	dist(float ax, float ay, float bx, float by);

#endif // CUB_RUN_H
