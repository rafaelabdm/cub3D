# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 01:34:24 by rapdos-s          #+#    #+#              #
#    Updated: 2023/03/23 16:38:39 by rapdos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		 = libft.a

SRC			 = ft_isalpha.c \
			   ft_isdigit.c \
			   ft_isalnum.c \
			   ft_isascii.c \
			   ft_isprint.c \
			   ft_strlen.c \
			   ft_memset.c \
			   ft_bzero.c \
			   ft_memcpy.c \
			   ft_memmove.c \
			   ft_strlcpy.c \
			   ft_strlcat.c \
			   ft_toupper.c \
			   ft_tolower.c \
			   ft_strchr.c \
			   ft_strrchr.c \
			   ft_strncmp.c \
			   ft_memchr.c \
			   ft_memcmp.c \
			   ft_strnstr.c \
			   ft_atoi.c \
			   ft_calloc.c \
			   ft_strdup.c \
			   ft_substr.c \
			   ft_strjoin.c \
			   ft_strtrim.c \
			   ft_split.c \
			   ft_itoa.c \
			   ft_strmapi.c \
			   ft_striteri.c \
			   ft_putchar_fd.c \
			   ft_putstr_fd.c \
			   ft_putendl_fd.c \
			   ft_putnbr_fd.c \
			   get_next_line.c

OBJ			 = ${SRC:%.c=%.o}

OBJ_C		 = 

UPDATE		 = NO

CC			 = cc

CFLAGS		 = -Wall -Werror -Wextra

RM			 = rm -f

AR			 = ar -rcs

LIBFT_MSG	 = "\033[1;36mLibft\033[0m:"

all: ${NAME}

$(NAME): ${OBJ} FORCE
	@if [ ${UPDATE} = "YES" ]; \
	then \
		echo ${LIBFT_MSG} Building ${NAME}; \
		${AR} ${NAME} ${OBJ_C}; \
	else \
		echo ${LIBFT_MSG} Nothing to be done for \'$@\'.; \
	fi

clean:
	@echo ${LIBFT_MSG} Removing ${NAME}\'s objects
	@${RM} ${OBJ}

fclean:
	@echo ${LIBFT_MSG} Removing ${NAME}\'s objects and ${NAME}
	@${RM} ${NAME} ${OBJ}

re: fclean all

%.o: %.c
	@${CC} -c ${CFLAGS} $< -o $@
	@echo ${LIBFT_MSG} Compiling ${@:.o=}
	$(eval OBJ_C += $@)
	$(eval UPDATE = YES)

FORCE:

.PHONY: all clean fclean re
