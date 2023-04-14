/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:24:09 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/03/23 16:24:09 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_run.h"

static int	render(t_cub *cub)
{
	check_keys (cub);
	draw_background (cub);
	raycast (cub);
	mlx_put_image_to_window (cub -> mlx, cub -> win, cub -> img.img_info, 0, 0);
	return (0);
}

void	cub_run(t_cub *cub)
{
	mlx_loop_hook (cub -> mlx, render, cub);
	mlx_loop(cub -> mlx);
}
