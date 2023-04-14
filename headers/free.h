/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:10:56 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/03/23 16:10:56 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include <stdlib.h>
# include <mlx.h>
# include "structs.h"

void	free_mat(char ***mat);
void	free_ptr(char **str);
void	free_memory(t_cub *cub);

#endif // FREE_H
