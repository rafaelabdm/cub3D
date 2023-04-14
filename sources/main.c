/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 07:55:35 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/03/23 07:55:35 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub_init.h"
#include "cub_run.h"
#include "cub_exit.h"

int	main(int argc, char *argv[])
{
	t_cub	cub;

	cub_init (argc, argv, &cub);
	cub_run (&cub);
}
