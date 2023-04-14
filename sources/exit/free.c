/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:12:06 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/03/23 16:12:06 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_mat(char ***mat)
{
	size_t	i;

	i = 0;
	while (*mat && mat[0][i])
		free_ptr (&mat[0][i++]);
	if (*mat)
		free (*mat);
	*mat = NULL;
}

void	free_ptr(char **str)
{
	free (*str);
	*str = NULL;
}

void	free_memory(t_cub *cub)
{
	if (cub -> textures.north_image)
		mlx_destroy_image (cub -> mlx, cub -> textures.north_image);
	if (cub -> textures.south_image)
		mlx_destroy_image (cub -> mlx, cub -> textures.south_image);
	if (cub -> textures.west_image)
		mlx_destroy_image (cub -> mlx, cub -> textures.west_image);
	if (cub -> textures.east_image)
		mlx_destroy_image (cub -> mlx, cub -> textures.east_image);
	if (cub -> img.img_info)
		mlx_destroy_image (cub -> mlx, cub -> img.img_info);
	if (cub -> mlx && cub -> win)
		mlx_destroy_window (cub -> mlx, cub -> win);
	if (cub -> mlx)
		mlx_destroy_display (cub -> mlx);
	free_mat (&cub -> scene_map);
	free_ptr ((char **)&cub -> mlx);
	free_ptr (&cub -> textures.north_file);
	free_ptr (&cub -> textures.south_file);
	free_ptr (&cub -> textures.west_file);
	free_ptr (&cub -> textures.east_file);
}
