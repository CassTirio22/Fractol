# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 18:02:26 by ctirions          #+#    #+#              #
#    Updated: 2021/07/05 16:43:56 by ctirions         ###   ########.fr        #
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

SRCS	=	main.c \
			srcs/display.c \
			srcs/init.c \
			srcs/move.c \
			srcs/utils.c \
			srcs/hook.c \

OBJS	=	${SRCS:.c=.o}

NAME	=	fractol.a

CFLAGS	= -Wall -Wextra -Werror

.c.o:		
			@gcc ${CFLAGS} -c -I./ $< -o ${<:.c=.o}
			@echo "${LIGHTPURPLE}Compilation : $< --> .o${RESET}"

$(NAME):	${OBJS}
			@ar -rcs ${NAME} ${OBJS}
			@ranlib ${NAME}
			@echo "${GREEN}Library done !${RESET}"
			@gcc -lmlx -framework OpenGL -framework AppKit ${NAME}
			@mv a.out fractol

all:		${NAME}

clean:		
			@rm -f ${OBJS}
			@echo "${RED}Clean done !${RESET}"

fclean:		clean
			@rm -f ${NAME}
			@rm fractol
			@echo "${RED}Fclean done !${RESET}"

re:			fclean all

.PHONY:		all clean fclean re