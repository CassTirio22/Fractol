# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 18:02:26 by ctirions          #+#    #+#              #
#    Updated: 2021/07/07 17:28:55 by ctirions         ###   ########.fr        #
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
			srcs/display.c \
			srcs/init.c \
			srcs/move.c \
			srcs/utils.c \
			srcs/hook.c

OBJS	=	${SRCS:.c=.o}


SRCS_BONUS	=	fractol_bonus.c \
				srcs_bonus/display.c \
				srcs_bonus/init.c \
				srcs_bonus/move.c \
				srcs_bonus/utils.c \
				srcs_bonus/hook.c \
				srcs_bonus/color.c \
				srcs_bonus/fractals/mandelbrot.c \
				srcs_bonus/fractals/julia.c \
				srcs_bonus/fractals/burningship.c 

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

NAME	=	fractol.a

CFLAGS	= -Wall -Wextra -Werror

.c.o:		
			@gcc ${CFLAGS} -c -I ./includes $< -o ${<:.c=.o}
			@echo "${LIGHTPURPLE}Compilation : $< --> .o${RESET}"

$(NAME):	${OBJS}
			@ar -rcs ${NAME} ${OBJS}
			@ranlib ${NAME}
			@gcc -lmlx -framework OpenGL -framework AppKit ${NAME}
			@mv a.out fractol

all:		${NAME}

bonus:		${OBJS_BONUS}
			@ar -rcs ${NAME} ${OBJS_BONUS}
			@ranlib ${NAME}
			@gcc -lmlx -framework OpenGL -framework AppKit ${NAME}
			@mv a.out fractol


clean:		
			@rm -f ${OBJS}
			@rm -f ${OBJS_BONUS}
			@echo "${RED}Clean done !${RESET}"

fclean:		clean
			@rm -f ${NAME}
			@rm fractol
			@echo "${RED}Fclean done !${RESET}"

re:			fclean all

.PHONY:		all clean fclean re