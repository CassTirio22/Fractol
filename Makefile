# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 18:02:26 by ctirions          #+#    #+#              #
#    Updated: 2021/08/22 17:53:34 by ctirions         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK		= $(shell tput -Txterm setaf 0)
RED			= $(shell tput -Txterm setaf 1)
GREEN		= $(shell tput -Txterm setaf 2)
YELLOW		= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	= $(shell tput -Txterm setaf 4)
PURPLE		= $(shell tput -Txterm setaf 5)
BLUE		= $(shell tput -Txterm setaf 6)
WHITE		= $(shell tput -Txterm setaf 7)
RESET		= $(shell tput -Txterm sgr0)

SRCS	=	fractol.c \
			srcs/color.c \
			srcs/display.c \
			srcs/hook.c \
			srcs/init.c \
			srcs/move.c \
			srcs/thread.c \
			srcs/utils.c \
			srcs/fractals/burningship.c \
			srcs/fractals/julia.c \
			srcs/fractals/mandelbrot.c \

OBJS	=	${SRCS:.c=.o}

NAME	=	fractol.a

CFLAGS	= -Wall -Wextra -Werror

.c.o:		
			@gcc ${CFLAGS} -c -I ./includes $< -o ${<:.c=.o}
			@echo "${LIGHTPURPLE}Compilation : $< --> .o${RESET}"

$(NAME):	${OBJS}
			@ar -rcs ${NAME} ${OBJS}
			@ranlib ${NAME}
			@gcc -lmlx -framework OpenGL -framework AppKit -lpthread ${NAME}
			@mv a.out fractol

all:		${NAME}

clean:		
			@rm -f ${OBJS}
			@echo "${RED}Clean done !${RESET}"

fclean:		clean
			@rm -f ${NAME}
			@echo "${RED}Fclean done !${RESET}"

re:			fclean all

.PHONY:		all clean fclean re