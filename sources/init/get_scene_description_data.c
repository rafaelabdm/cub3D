/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_description_data.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:00:57 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/03/23 17:00:57 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_init.h"

static int	get_color(int *color, char *line)
{
	t_get_color	c;

	ft_bzero (&c, sizeof (t_get_color));
	c.ret = 1;
	c.start = 2;
	c.len = ft_strchr (line + c.start, ',') - line - c.start;
	c.temp[0] = ft_substr (line, c.start, c.len);
	*color = ft_atoi (c.temp[0]) << 16;
	c.start += c.len + 1;
	c.len = ft_strchr (line + c.start, ',') - line - c.start;
	c.temp[1] = ft_substr (line, c.start, c.len);
	*color |= ((unsigned char) ft_atoi (c.temp[1])) << 8;
	c.start += c.len + 1;
	c.len = ft_strchr (line + c.start, '\0') - line - c.start;
	c.temp[2] = ft_substr (line, c.start, c.len);
	*color |= ((unsigned char) ft_atoi (c.temp[2]));
	if (!c.temp[0] || !c.temp[1] || !c.temp[2])
		c.ret = -1;
	free_ptr (&c.temp[0]);
	free_ptr (&c.temp[1]);
	free_ptr (&c.temp[2]);
	return (c.ret);
}

static int	set_data(t_cub *cub, char *line)
{
	size_t		len;
	int			ret;
	static int	start;

	len = 0;
	ret = 0;
	while (line[len] && line[len] != '\n')
		len++;
	if (!ft_strncmp (line, "NO ", 3) && !start)
		cub -> textures.north_file = ft_strtrim(line, "NO \n\r");
	else if (!ft_strncmp (line, "SO ", 3) && !start)
		cub -> textures.south_file = ft_strtrim(line, "SO \n\r");
	else if (!ft_strncmp (line, "WE ", 3) && !start)
		cub -> textures.west_file = ft_strtrim(line, "WE \n\r");
	else if (!ft_strncmp (line, "EA ", 3) && !start)
		cub -> textures.east_file = ft_strtrim(line, "EA \n\r");
	else if (!ft_strncmp (line, "F ", 2) && !start)
		ret = get_color (&cub -> colors.floor, line);
	else if (!ft_strncmp (line, "C ", 2) && !start)
		ret = get_color (&cub -> colors.ceiling, line);
	else if (ft_strchr("NWES01 ", line[0]) || start)
		start = get_map (cub, line);
	return (ret);
}

void	get_scene_description_data(t_cub *cub)
{
	char	*line;
	int		fd;
	int		error;

	fd = open (cub -> scene_description, O_RDONLY);
	if (fd == -1)
		cub_exit (cub, "Can't open scene description file.", 1);
	line = get_next_line (fd);
	error = 0;
	while (line && error >= 0)
	{
		error += set_data (cub, line);
		free_ptr (&line);
		line = get_next_line (fd);
	}
	if (error < 2)
	{
		while (line)
		{
			free_ptr (&line);
			line = get_next_line (fd);
		}
	}
	if (error < 2)
		cub_exit (cub, "Invalid scene information.", 1);
}
