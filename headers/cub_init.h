/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:42:12 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/03/23 15:42:12 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_INIT_H
# define CUB_INIT_H

# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <unistd.h>

# include "libft.h"
# include "free.h"
# include "structs.h"
# include "cub_run.h"
# include "cub_exit.h"

# define WIN_NAME "Cub3d"
# define WIN_HEIGHT 600
# define WIN_WIDTH 960

typedef struct s_get_color
{
	size_t	start;
	char	*temp[3];
	size_t	len;
	int		ret;
}			t_get_color;

void	cub_init(int argc, char *argv[], t_cub *cub);
void	get_scene_description_data(t_cub *cub);
void	format_map(char ***map, size_t map_height, size_t map_width);
int		get_map(t_cub *cub, char *line);
void	check_map(t_cub *cub);
void	get_player_info(t_cub *cub);
void	cub_mlx_init(t_cub *cub);

#endif // CUB_INIT_H
