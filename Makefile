# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 16:43:51 by maparigi          #+#    #+#              #
#    Updated: 2022/08/27 16:48:00 by maparigi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------colors-----------#
NC=\033[0m

Black=\033[0;30m
Red=\033[0;31m
Green=\033[0;32m
Yellow=\033[0;33m
Blue=\033[0;34m
Purple=\033[0;35m
Cyan=\033[0;36m
White=\033[0;37m
#---------------------------#

NAME = philo

CC = gcc

INC =	./includes

LIBFT_PATH = ./libft/
LIBFT = ${LIBFT_PATH}libft.a

SRCS =	main.c			\

OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

CFLAGS = -Wall -Wextra -Werror -pthread -MMD -MP

.c.o:
	@${CC} ${CFLAGS} -I${INC} -c $< -o $@

all:	${LIBFT} ${NAME}

${NAME}: ${OBJS}
	@echo "${Red}Compiling${NC} : ${Purple}${NAME}${NC}"
	${CC} ${OBJS} ${CFLAGS} ${LIBFT} -o ${NAME}
	@echo "${Purple}${NAME}${NC} : has been successfully compiled."

${LIBFT}:
	@make -sC libft

val:	${NAME}
	valgrind \
	--leak-check=full --tool=memcheck \
	--show-reachable=yes \
	--track-fds=yes \
	--errors-for-leak-kinds=all \
	--show-leak-kinds=all ./${NAME} fichier.txt

clean:
	@rm -f ${OBJS} ${DEPS}
	@make -sC libft clean

fclean: clean
	@rm -f ${NAME}
	@make -sC libft fclean

aclean: all clean

re: fclean all

-include : $(DEPS)

.PHONY: all clean fclean re bonus aclean val
