# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 08:28:02 by rapdos-s          #+#    #+#              #
#    Updated: 2023/01/12 08:28:02 by rapdos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		 = cub3D

SRC_DIR		 = sources/

HDR_DIR		 = headers/

OBJ_DIR		 = objects/

LFT_DIR	 = libft/

SRC			 = main.c \
			   cub_init.c \
			   cub_mlx_init.c \
			   get_scene_description_data.c \
			   get_map.c \
			   check_map.c \
			   cub_run.c \
			   actions.c \
			   draw_background.c \
			   draw_pixel.c \
			   draw_rectangle.c \
			   choose_wall_math.c \
			   draw_3d_scene.c \
			   raycast_utils.c \
			   raycast.c \
			   player_movement.c \
			   free.c \
			   cub_exit.c

HDR			 = structs.h \
			   cub_init.h \
			   cub_run.h \
			   free.h \
			   cub_exit.h

HDR			:= ${addprefix ${HDR_DIR}, ${HDR}}

OBJ			 = ${addprefix ${OBJ_DIR}, ${SRC:%.c=%.o}}

LIBFT		 = ${LFT_DIR}libft.a

VPATH		 = init/ run/ exit/

VPATH		:= ${SRC_DIR} ${addprefix ${SRC_DIR}, ${VPATH}}

INCLUDE		 = ${HDR_DIR} ${LFT_DIR}

INCLUDE		:= ${addprefix -I, ${INCLUDE}}

CFLAGS		 = -Wall -Werror -Wextra

MKFLAGS		 = -j35 -s --no-print-directory --directory=${LFT_DIR}

MLXFLAGS	 = -lmlx -lXext -lX11

MTFLAGS		 = -lm

OT_FLAGS	 = ${MLXFLAGS} ${MTFLAGS}

CC			 = cc

RM			 = rm -rf

UPDATE		 = NO

CUB3D_MSG	 = "\033[1;35mcub3D\033[0m:"

RECIPE_NAME	 = ${NAME}

all: set_recipe_name ${NAME}

${NAME}: ${OBJ_DIR} ${OBJ} FORCE
	@make ${MKFLAGS} | \
	tee /dev/stderr | \
	if grep -q "Nothing to be done for "; \
	then \
		if [ ${UPDATE} = YES ]; \
		then \
			echo ${CUB3D_MSG} Building ${NAME}; \
			${CC} ${CFLAGS} ${OBJ} ${INCLUDE} ${LIBFT} ${OT_FLAGS} -o ${NAME}; \
		else \
			echo ${CUB3D_MSG} Nothing to be done for \'${RECIPE_NAME}\'.; \
		fi \
	else \
		echo ${CUB3D_MSG} Building ${NAME}; \
		${CC} ${CFLAGS} ${OBJ} ${INCLUDE} ${LIBFT} ${OT_FLAGS} -o ${NAME}; \
	fi

clean:
	@echo ${CUB3D_MSG} Removing ${NAME}\'s objects
	@${RM} ${OBJ_DIR}
	@make clean ${MKFLAGS}

fclean:
	@echo ${CUB3D_MSG} Removing ${NAME}\'s  objects and binaries
	@make fclean ${MKFLAGS}
	@${RM} ${NAME} ${OBJ_DIR}

re: fclean all

${OBJ_DIR}:
	@mkdir -p ${OBJ_DIR}

${OBJ_DIR}%.o: %.c ${HDR}
	@echo ${CUB3D_MSG} Compiling $@
	@${CC} -c ${CFLAGS} ${INCLUDE} $< -o $@
	$(eval UPDATE = YES)

set_recipe_name:
	$(eval RECIPE_NAME = all)

FORCE:

.PHONY: all set_recipe_name clean fclean re FORCE
