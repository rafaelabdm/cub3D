/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:07:44 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/03/24 15:07:44 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_init.h"

static void	set_temp(char ***map, size_t map_height, size_t map_width)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	map[0] = ft_calloc (map_height + 1, sizeof (char *));
	temp = map_height;
	while (temp--)
		map[0][temp] = ft_calloc (map_width + 1, sizeof (char *));
	i = 0;
	while (map_height--)
	{
		j = 0;
		temp = map_width;
		while (temp--)
		{
			map[0][i][j] = ' ';
			j++;
		}
		i++;
	}
}

static void	get_direction(t_cub *cub, size_t x, size_t y)
{
	cub -> p.x = x + 0.5;
	cub -> p.y = y + 0.5;
	cub -> p.col_x = x * (WIN_WIDTH / cub -> map_width);
	cub -> p.col_y = y * (WIN_HEIGHT / cub -> map_height);
	cub -> p.direction = cub -> scene_map[y][x];
	if (cub -> scene_map[y][x] == 'N')
		cub -> p.ang = PI / 2;
	if (cub -> scene_map[y][x] == 'E')
		cub -> p.ang = PI;
	if (cub -> scene_map[y][x] == 'S')
		cub -> p.ang = 3 * PI / 2;
	cub -> p.dx = cos (cub -> p.ang);
	cub -> p.dy = sin (cub -> p.ang);
}

void	get_player_info(t_cub *cub)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (cub -> scene_map && cub -> scene_map[y])
	{
		x = 0;
		while (cub -> scene_map[y] && cub -> scene_map[y][x])
		{
			if (ft_strchr ("NSWE", cub -> scene_map[y][x]))
				get_direction (cub, x, y);
			x++;
		}
		y++;
	}
}

void	format_map(char ***map, size_t map_height, size_t map_width)
{
	char	**temp;
	size_t	i;
	size_t	j;

	set_temp(&temp, map_height, map_width);
	i = 0;
	while (map[0] && map[0][i])
	{
		j = 0;
		while (map[0][i] && map[0][i][j])
		{
			if (map[0][i][j] == '\n')
				map[0][i][j] = ' ';
			temp[i][j] = map[0][i][j];
			j++;
		}
		i++;
	}
	free_mat (map);
	map[0] = temp;
}

int	get_map(t_cub *cub, char *line)
{
	char	**temp;
	int		i;

	cub -> map_height++;
	temp = ft_calloc (cub -> map_height + 1, sizeof (char *));
	if (!temp)
		cub_exit (cub, "Can't allocate memory.", 1);
	i = 0;
	while (cub -> scene_map && cub -> scene_map[i])
	{
		temp[i] = ft_strdup (cub -> scene_map[i]);
		i++;
	}
	if (cub -> map_width < (int) ft_strlen (line))
		cub -> map_width = (int) ft_strlen (line);
	temp[i] = ft_strdup (line);
	free_mat (&cub -> scene_map);
	cub -> scene_map = temp;
	return (1);
}
