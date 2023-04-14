/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 07:50:59 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/03/24 07:50:59 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_run.h"

void	draw_pixel(t_img *img, int x, int y, int color)
{
	unsigned char	*pixel;
	int				i;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	i = img -> bpp - 8;
	pixel = (unsigned char *)(img -> addr + (y * img -> line_len \
	+ x * (img -> bpp / 8)));
	while (i >= 0)
	{
		if (img -> endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img -> bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
