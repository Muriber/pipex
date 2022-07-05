# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 09:16:08 by bjimenez          #+#    #+#              #
#    Updated: 2022/07/05 13:25:43 by bjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= pipex.c pipex_utils.c pipex_utils_libft.c

BSRCS		= pipex_bonus.c pipex_utils.c pipex_utils_libft.c

OBJS		= ${SRCS:.c=.o}

BOBJS		= ${BSRCS:.c=.o}

CFLAGS		= -Wall -Wextra -Werror

CC			= gcc

NAME		= libpipex.a

RM			= rm -f

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@
			
all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs ${NAME} ${OBJS}
			$(CC) $(CFLAGS) -lpipex -L. -o pipex

bonus:		fclean $(BOBJS)
			ar rcs ${NAME} ${BOBJS}
			$(CC) $(CFLAGS) -lpipex -L. -o pipex

clean:		
			${RM} ${OBJS} ${BOBJS}

fclean:		clean
			${RM} ${NAME}
			
re:			fclean all

.PHONY:		all clean fclean re