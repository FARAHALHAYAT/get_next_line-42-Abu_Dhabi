# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fasharif <fasharif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 17:46:21 by fasharif          #+#    #+#              #
#    Updated: 2022/08/30 16:49:32 by fasharif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
SRCS = get_next_line.c  get_next_line_utils.c
BONUS = get_next_line_bonus.c  get_next_line_utils_bonus.c
OBJS = ${SRCS:.c=.o}
OBJSBONUS = ${BONUS:.c=.o}
CC		= gcc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror
.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}
$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}
bonus: ${OBJSBONUS}
		ar rcs ${NAME} ${OBJSBONUS}
all:	${NAME}
clean:
		${RM} ${OBJS} ${OBJSBONUS}
fclean:	clean
		${RM} ${NAME}
re:		fclean all
