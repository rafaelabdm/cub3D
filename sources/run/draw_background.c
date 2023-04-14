/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 07:30:56 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/03/24 07:30:56 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_run.h"

void	draw_background(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			draw_pixel (&cub -> img, x, y, cub -> colors.ceiling);
			draw_pixel (
				&cub -> img, x, y + WIN_HEIGHT / 2, \
				cub -> colors.floor \
			);
			x++;
		}
		y++;
	}
}
