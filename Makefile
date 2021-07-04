# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 18:02:26 by ctirions          #+#    #+#              #
#    Updated: 2021/07/04 18:14:44 by ctirions         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c \
			srcs/display.c \
			srcs/init.c \
			srcs/move.c \
			srcs/utils.c \
			srcs/hook.c \

OBJS	=	${SRCS:.c=.o}

NAME	=	fractol.a

.c.o:		
			@gcc -c -I./ $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			@ar -rcs ${NAME} ${OBJS}
			@gcc -lmlx -framework OpenGL -framework AppKit ${NAME}
			@mv a.out fractol

all:		${NAME}

clean:		
			@rm -f ${OBJS}

fclean:		clean
			@rm -f ${NAME}
			@rm fractol

re:			fclean all

.PHONY:		all clean fclean re