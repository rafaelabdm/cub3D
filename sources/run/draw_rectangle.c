/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:57:45 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/03/24 10:57:45 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_run.h"

void	draw_rectangle(t_cub *cub, t_coord start, t_coord end, int color)
{
	int	x;
	int	y;

	y = start.y;
	while (y <= end.y)
	{
		x = start.x;
		while (x <= end.x)
		{
			draw_pixel (&cub -> img, x, y, color);
			x++;
		}
		y++;
	}
}
