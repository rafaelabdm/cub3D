/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:41:41 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/03/23 15:41:41 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_init.h"

static void	check_argc(int argc, t_cub *cub)
{
	if (argc != 2)
		cub_exit (cub, "Invalid Usage.", 1);
}

static void	get_scene_description_file_name(char *map_name, t_cub *cub)
{
	char	*extension_start;

	cub -> scene_description = map_name;
	extension_start = ft_strrchr (cub -> scene_description, '.');
	if (ft_strncmp (extension_start, ".cub", ft_strlen (".cub") + 1))
		cub_exit (cub, "Invalid scene description file extension.", 1);
}

static void	cub_bzero(t_cub *cub)
{
	ft_bzero (cub, sizeof (t_cub));
	ft_bzero (&cub -> img, sizeof (t_img));
	ft_bzero (&cub -> textures, sizeof (t_texture));
	ft_bzero (&cub -> colors, sizeof (t_color));
}

void	cub_init(int argc, char *argv[], t_cub *cub)
{
	cub_bzero(cub);
	check_argc (argc, cub);
	get_scene_description_file_name (argv[1], cub);
	get_scene_description_data (cub);
	format_map (&cub -> scene_map, cub -> map_height, cub -> map_width);
	cub -> map_width--;
	get_player_info (cub);
	if (!cub->scene_map || !(int)cub -> p.y || !cub -> p.x)
		cub_exit (cub, "Invalid scene information.", 1);
	check_map(cub);
	cub_mlx_init (cub);
}
