# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 16:43:51 by maparigi          #+#    #+#              #
#    Updated: 2022/11/30 22:11:09 by maparigi         ###   ########.fr        #
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

SRCS =	main.c			\
		init.c			\
		time.c			\
		utils.c			\
		actions.c		\

OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

CFLAGS = -Wall -Wextra -Werror -pthread -MMD -MP

.c.o:
	@${CC} ${CFLAGS} -I${INC} -c $< -o $@

all:	${NAME}

${NAME}: ${OBJS}
	@echo "${Red}Compiling${NC} : ${Purple}${NAME}${NC}"
	${CC} ${OBJS} ${CFLAGS} -o ${NAME}
	@echo "${Purple}${NAME}${NC} : has been successfully compiled."

val:	${NAME}
	valgrind \
	--leak-check=full --tool=memcheck \
	--show-reachable=yes \
	--track-fds=yes \
	--errors-for-leak-kinds=all \
	--show-leak-kinds=all ./${NAME} fichier.txt

clean:
	@rm -f ${OBJS} ${DEPS}
	@rm -rdf objects dependencies
	# @rm -dfi objects dependencies

fclean: clean
	@rm -f ${NAME}

aclean: all clean

re: fclean all

poubelle:
	@mkdir -p objects
	@mkdir -p dependencies

menage: poubelle
	@mv -f ${OBJS} objects
	@mv -f ${DEPS} dependencies

-include : $(DEPS)

.PHONY: all clean fclean re bonus aclean val poubelle menage
