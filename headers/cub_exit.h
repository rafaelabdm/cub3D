/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_exit.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:20:36 by rapdos-s          #+#    #+#             */
/*   Updated: 2023/03/23 16:20:36 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_EXIT_H
# define CUB_EXIT_H

# include <unistd.h>
# include <stdlib.h>

# include "structs.h"
# include "libft.h"
# include "free.h"

# define ERROR_MSG	"\033[1;31mError\n\033[0m"
# define EXIT_MSG	"\033[1;35mSee you soon, human!\033[0m"

int		cub_close(t_cub *cub);
void	cub_exit(t_cub *cub, const char *msg, const int code);

#endif // CUB_EXIT_H
