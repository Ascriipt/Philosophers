# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 04:14:10 by maparigi          #+#    #+#              #
#    Updated: 2022/06/12 14:43:29 by maparigi         ###   ########.fr        #
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

NAME = libft.a

CC = gcc

INC = ../includes

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c \
	   ft_isalpha.c ft_isascii.c \
	   ft_isdigit.c ft_isprint.c \
	   ft_memcmp.c ft_memcpy.c \
	   ft_memmove.c ft_memset.c \
	   ft_putchar_fd.c ft_putendl_fd.c \
	   ft_putnbr_fd.c ft_putstr_fd.c \
	   ft_strchr.c ft_strdup.c \
	   ft_strlcat.c ft_strlcpy.c \
	   ft_strlen.c ft_strnstr.c \
	   ft_strrchr.c ft_substr.c \
	   ft_tolower.c ft_toupper.c \
	   ft_memccpy.c ft_striteri.c \
	   ft_memchr.c ft_strmapi.c \
	   ft_calloc.c ft_strtrim.c \
	   ft_strjoin.c ft_split.c \
	   ft_strncmp.c ft_itoa.c

SRCS_BONUS = ft_lstnew.c ft_lstdelone.c \
			 ft_lstclear.c ft_lstiter.c \
			 ft_lstlast.c ft_lstsize.c \
			 ft_lstadd_front.c ft_lstadd_back.c \
			 ft_lstmap.c 

OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

.c.o:
	@gcc ${CFLAGS} -I${INC} -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJS} ${OBJS_BONUS}
	@echo "${Red}Compiling${NC} : ${Purple}libft${NC}"
	ar rcs ${NAME} ${OBJS} ${OBJS_BONUS}
	@echo "${Purple}libft${NC} : has been successfully compiled."

clean:
	@rm -f ${OBJS} ${OBJS_BONUS} $(DEPS)

fclean: clean
	@rm -f ${NAME}

re: fclean all

-include : $(DEPS)

.PHONY: all clean fclean re bonus
