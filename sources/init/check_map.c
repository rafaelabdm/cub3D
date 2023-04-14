/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabustam <rabustam@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:00:40 by rabustam          #+#    #+#             */
/*   Updated: 2023/04/11 23:26:27 by rabustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_init.h"

static void	check_border(t_cub *cub, char **map, int y)
{
	int	x;

	x = 0;
	while (x < cub -> map_width)
	{
		if (map[y][x] != ' ' && map[y][x] != '1')
			cub_exit (cub, "Invalid Map.", 7);
		if (y == 0 && map[y][x] == ' ')
		{
			if (map[1][x] != ' ' && map[1][x] != '1')
				cub_exit (cub, "Invalid Map.", 8);
		}
		else if (y == cub -> map_height - 1 && map[y][x] == ' ')
		{
			if (map[y - 1][x] != ' ' && map[y - 1][x] != '1')
				cub_exit (cub, "Invalid Map.", 9);
		}		
		x++;
	}
}

static void	check_arround_middle(t_cub *cub, int y, int x, char **map)
{
	if (x == 0 && map[y][x] == ' ')
	{
		if ((map[y][x + 1] != ' ' && map[y][x + 1] != '1') || \
		(map[y - 1][x] != ' ' && map[y - 1][x] != '1') || \
		(map[y + 1][x] != ' ' && map[y + 1][x] != '1'))
			cub_exit (cub, "Invalid Map.", 4);
	}
	else if (x == cub -> map_width - 1 && map[y][x] == ' ')
	{
		if (((map[y][x - 1] != ' ' && map[y][x - 1] != '1') || \
		(map[y - 1][x] != ' ' && map[y - 1][x] != '1') || \
		(map[y + 1][x] != ' ' && map[y + 1][x] != '1')))
			cub_exit (cub, "Invalid Map.", 5);
	}
	else if (map[y][x] == ' ')
	{
		if (((map[y][x - 1] != ' ' && map[y][x - 1] != '1') || \
		(map[y][x + 1] != ' ' && map[y][x + 1] != '1') || \
		(map[y - 1][x] != ' ' && map[y - 1][x] != '1') || \
		(map[y + 1][x] != ' ' && map[y + 1][x] != '1')))
			cub_exit (cub, "Invalid Map.", 6);
	}
}

static void	check_middle(t_cub *cub, char **map, int y)
{
	int	x;

	x = 0;
	while (x < cub -> map_width)
	{
		if (x == 0 || x == cub -> map_width - 1)
		{
			if (map[y][x] != ' ' && map[y][x] != '1')
				cub_exit (cub, "Invalid Map.", 3);
		}
		check_arround_middle(cub, y, x, map);
		x++;
	}
}

static void	check_characters(t_cub *cub, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (y < cub -> map_height)
	{
		x = 0;
		while (x < cub -> map_width)
		{
			if (!ft_strchr("NSEW01 ", map[y][x]))
				cub_exit (cub, "Invalid Map.", 1);
			x++;
		}
		y++;
	}
}

void	check_map(t_cub *cub)
{
	int	y;

	y = 0;
	check_characters(cub, cub -> scene_map);
	while (cub -> scene_map[y])
	{
		if (y == 0 || y == cub -> map_height - 1)
			check_border(cub, cub -> scene_map, y);
		else
			check_middle(cub, cub -> scene_map, y);
		y++;
	}
}
