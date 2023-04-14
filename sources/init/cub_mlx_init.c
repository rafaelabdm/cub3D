/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mlx_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 08:16:42 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/04/04 08:16:42 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_init.h"

static void	init_cub(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		cub_exit(cub, "Can't init mlx's Xserver connection.", 1);
	cub->img.img_info = mlx_new_image(cub->mlx, WIN_WIDTH, WIN_HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img_info, &cub->img.bpp, \
		&cub->img.line_len, &cub->img.endian);
}

void	init_texture(t_cub *cub)
{
	int	temp_height;
	int	temp_width;

	cub->textures.north_image = mlx_xpm_file_to_image(cub->mlx, \
		cub->textures.north_file, &cub->textures.height, &cub->textures.width);
	if (cub->textures.height != cub->textures.width)
		cub_exit(cub, "All textures must be square.", 1);
	temp_height = cub->textures.height;
	temp_width = cub->textures.width;
	cub->textures.south_image = mlx_xpm_file_to_image(cub->mlx, \
		cub->textures.south_file, &cub->textures.height, &cub->textures.width);
	if (temp_height != cub->textures.height || \
		temp_width != cub->textures.width)
		cub_exit(cub, "Can't import texture.", 1);
	cub->textures.west_image = mlx_xpm_file_to_image(cub->mlx, \
		cub->textures.west_file, &cub->textures.height, &cub->textures.width);
	if (temp_height != cub->textures.height || \
		temp_width != cub->textures.width)
		cub_exit(cub, "Can't import texture.", 1);
	cub->textures.east_image = mlx_xpm_file_to_image(cub->mlx, \
		cub->textures.east_file, &cub->textures.height, &cub->textures.width);
	if (temp_height != cub->textures.height || \
		temp_width != cub->textures.width)
		cub_exit(cub, "Can't import texture.", 1);
}

void	cub_mlx_init(t_cub *cub)
{
	init_cub(cub);
	init_texture(cub);
	if (!cub->textures.north_image || !cub->textures.south_image || \
		!cub->textures.west_image || !cub->textures.east_image)
		cub_exit(cub, "Can't import texture.", 1);
	cub->win = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (!cub->win)
		cub_exit(cub, "Can't init game window.", 1);
	mlx_hook(cub->win, 2, (1L << 0), button_down, cub);
	mlx_hook(cub->win, 3, (1L << 1), button_up, cub);
	mlx_hook(cub->win, 17, 0, cub_close, cub);
}
