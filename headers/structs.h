/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 07:54:22 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/03/23 07:54:22 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_img
{
	void	*img_info;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_texture
{
	int		height;
	int		width;
	char	*north_file;
	char	*south_file;
	char	*west_file;
	char	*east_file;
	void	*north_image;
	void	*south_image;
	void	*west_image;
	void	*east_image;
}	t_texture;

typedef struct s_color
{
	int	floor;
	int	ceiling;
}	t_color;

typedef struct s_keys
{
	int	esc;
	int	up;
	int	down;
	int	left;
	int	right;
	int	w;
	int	a;
	int	s;
	int	d;
}	t_keys;

typedef struct s_player
{
	float	x;
	float	y;
	float	col_x;
	float	col_y;
	float	dx;
	float	dy;
	float	ang;
	int		direction;
}			t_player;

typedef struct s_cub
{
	void		*mlx;
	void		*win;
	char		*scene_description;
	char		**scene_map;
	int			map_height;
	int			map_width;
	t_img		img;
	t_texture	textures;
	t_color		colors;
	t_keys		keys;
	t_player	p;
}	t_cub;

#endif // STRUCTS_H
